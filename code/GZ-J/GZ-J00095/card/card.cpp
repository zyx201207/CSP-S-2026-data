// GZ-J00095 贵阳市白云区华师一学校 王舒越 
#include<bits/stdc++.h>
#define ll long long
#define MAXN 500010
using namespace std;
ll n,m,a[MAXN],t[MAXN],f[MAXN],s[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll k=1;k<=n;k++){
		memset(f,0,sizeof(f));
		memset(s,1,sizeof(s));
		for(ll i=k;i<=n;i++){
			f[a[i]]++,t[a[i]]++;
			if(f[a[i]]>1){
				for(ll j=k,fj=0;j<i;j++){
					if(a[j]==a[i]) fj=1;
					if(fj && s[j]){
						t[a[j]]--,f[a[j]]--,s[j]=0;
					}
				}
			}
		}
	}
	for(ll i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
