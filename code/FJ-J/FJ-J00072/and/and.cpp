#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e5+5;
int a[N],n,m,f[N];
vector<int> e[29];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=29;j>=0;j--){
		for(int i=1;i<=n;i++){
			if(a[i]&(1<<j)){
				e[j].push_back(i);
			}
		}
	}
	int ans=0,k1=0;
	bool f1=1;
	for(int i=29;i>=0;i--){
		if(e[i].size()<m){
			continue;
		}
		if(f1){
			for(auto k:e[i]){
				f[k]=1;
			}
			k1=1;
			f1=0;
			ans+=(1<<i);
		}
		else{
			int kk=0;
			for(auto k:e[i]){
				if(f[k]==k1){
					kk++;
				}
			}
			if(kk<m){
				continue;
			}
			for(auto k:e[i]){
				f[k]++;
			}
			k1++;
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}