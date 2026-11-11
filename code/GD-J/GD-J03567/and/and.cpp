#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],cnt[40];
vector<long long> g[N],tmp[40],tt,t2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int t=a[i];
		for(int flag=0;flag<=31;flag++){
			if(t&(1<<flag)){
				cnt[flag]++;
				tmp[flag].push_back(a[i]);
			}
		}
	}
	
	long long f=0,ti=0;
	for(int i=31;i>=0;i--){
		if(cnt[i]>=m){
			if(!f){
				ti=i;
				f=1;
				for(int v:tmp[i]){
					tt.push_back(v);
				}	
			}else{
				int cnt0=0;
				for(int v:tmp[i]){
					bool f=1;
					for(int j=ti;j>=i+1;j--){
						if(!(v&(1<<j)))f=0;
					}
					if(f){
						cnt0++;
						t2.push_back(v);
					}
				}
				if(cnt0>=m){
					tt.clear();
					for(int v:t2){
						tt.push_back(v);
					}
					t2.clear();
				}else{
					t2.clear();
				}
			}
		}
	}
	long long ans=tt[0];
	for(int i=1;i<tt.size();i++){
		ans&=tt[i];
	}
	cout<<ans<<" ";
	return 0;
}
