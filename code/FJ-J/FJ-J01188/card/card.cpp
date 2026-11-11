#include<bits/stdc++.h>
#define ll long long
const int N=2e5+10;
using namespace std;
ll a[N],n,m,t[N],s[N],ans[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int _=1;_<=n;_++){
		int b=1,e=1;
		for(int i=_;i<=n;i++){
			if(t[a[i]]!=0){
				t[s[e]]--;
				while(s[e--]!=a[i]){
					if(e==0)cout<<111;
					t[s[e]]--;
				}
			}
			s[++e]=a[i];t[a[i]]++;
		}
		for(int i=1;i<=e;i++){
			ans[s[i]]++;t[a[i]]=0;s[i]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
