//GZ-J00288 ∑ΩÍ…”Ó 
#include <bits/stdc++.h>
using namespace std;
int n,m;
int p=1;
int a[500005];
int s[500005];
bool b[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(s[p]!=a[j]){
					s[p]=0;
					p--;
				}
			}
			else{
				s[p]=a[j];
				b[s[p]]=1;
				p++;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[a[i]]) ans[a[i]]++;
		}
	}
	for(int i=1;i<=-m;i++){
		cout<<ans[i];
	}
	return 0;
}
