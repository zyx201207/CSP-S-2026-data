#include <bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m,a[N],er[N][50];
void chai(int idx){
	int i=0,num=a[idx];
	unsigned int k=1;
	while(k<=num){
		k<<=1;
		i++;
	}
	k>>=1;
	i--;
//	cout<<i<<"\n";
//	int cnt=1;
	while(num){
//		if(cnt<=10) cout<<k<<"\n";
//		cnt++;
		if(num>=k){
			er[idx][i]=1;
			num-=k;
		}
		k>>=1; 
		i--;
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		chai(i);
	}
	vector<int> in;
	for(int i=1;i<=n;i++){
		in.push_back(i);
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int k=0;k<int(in.size());k++){
			if(er[in[k]][i]){
				sum++;
			}
		}
//		cout<<sum<<" ";
		
		if(sum>=m){
			vector<int> tmp;
			for(int k=0;k<int(in.size());k++){
				if(er[in[k]][i]){
					tmp.push_back(in[k]);
				}
			}
			in=tmp;
		}
		if(sum==m){
			break;
		}
	}
//	cout<<"\n";
	int cnt=0;
	long long ans=(1<<31)-1;
	for(int k=0;k<int(in.size());k++){
//		cout<<a[in[k]]<<"\n";
		ans&=a[in[k]];
		cnt++;
		if(cnt==m) break;
	}
	cout<<ans<<"\n";
	return 0;
}

