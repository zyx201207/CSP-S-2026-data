#include <bits/stdc++.h>
using namespace std;
struct stu{
	long long t;
	string s;
}f[20005];
void solve(){
	long long n,ans=0;
	cin>>n;
	int v=0;
	for(int i=1;i<=n;i++){
		cin>>f[i].t>>f[i].s;
		if(f[i-1].s!=f[i].s){
			v=1;
		}
	}
	if(v==0){
		cout<<0;
		return;
	}
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		if(r==l){
		cout<<ans;
		return;
		}
		if(f[l].t==f[r].t&&f[l].s==f[r].s){
			r--;
			l++;
		}else{
			if(f[l].s!=f[r].s){
				if(f[r].t>f[l].t){
					ans+=f[l].t;
					f[r].t-=f[l].t;
					l++;
				}else{
					ans+=f[r].t;
					f[l].t-=f[r].t;
					r--;
				}
			}else{
			if(f[l].t!=f[r].t){
				if(f[l].t>f[r].t){
					f[l].t-=f[r].t;
					r--;
				}else{
					f[r].t-=f[l].t;
					l++;
				}
			}	
			}	
		} 
		
		
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
