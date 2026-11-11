#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
f[i][j] -> a[i]的二进制第j位

5 3
13 25 23 15 19
0000 1101
0001 1001
0001 0111
0000 1111
0001 0011

5 3
31 3 1 15 7
* 
11 4
1 2 3 2 4 3 2 1 4 3 1
*/
int n,m;
ll ycl[31];
long long a[200005];
vector<ll>sum[35];
int mx=0;
ll ans=0;
void opt(int id){
	if(id!=0)ans+=ycl[id-1];
	int mmxx=0;
	for(int i=id-1;i>=1;i--){
		sum[i].clear();
		for(int j=0;j<sum[id].size();j++){
			if(sum[id][j]&(1<<(i-1))){
				sum[i].push_back(sum[id][j]);
			}
		}
		if(sum[i].size()>=m){
			mmxx=i;
			break;
		}
	}
	if(mmxx==0){
		cout<<ans;
		return;
	}
	//cout<<mmxx<<endl;
	opt(mmxx);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ycl[0]=1;
	for(int i=1;i<=30;i++){
		ycl[i]=ycl[i-1]*2;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll k=a[i];
		int idx=0;//=upper_bound(yc1,ycl+31,a[i])-ycl;
		//sum[idx].push_back(a[i]);
		//ll one=1;
		while(k){
			idx++;
			k=k/2;
			sum[idx].push_back(a[i]);
		}
		if(sum[idx].size()>=m)mx=max(mx,idx);
		//cout<<idx<<" ";
	}
	//此时最高位是第mx位
	//cout<<mx<<endl;
	opt(mx);
	return 0;
}
