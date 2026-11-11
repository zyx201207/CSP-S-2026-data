#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000001],ans,bj[1000001];
vector<int>l[40];
void wys(int s,int bh){
	int cnt=1;
	while(s>0){
		if(s%2==1) l[cnt].push_back(bh);
		cnt++,s/=2;
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		wys(a[i],i);
	}
	int z=0;
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=0;j<l[i].size();j++){
			int k=l[i][j];
			if(bj[k]==z) cnt++;
		}
		if(cnt>=m){
			z++;
			for(int j=0;j<l[i].size();j++){
				int k=l[i][j];
				if(bj[k]==z-1) bj[k]=z;
			}
		}
	}
	int cnt1=0;
	for(int i=1;i<=n;i++){
		if(cnt1==m) break;
		if(bj[i]==z){
			cnt1++;
			if(cnt1==1) ans=a[i];
			else ans=ans&a[i];
		}
	}
	cout<<ans;
	return 0;
} 
