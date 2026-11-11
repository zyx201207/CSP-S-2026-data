//GZ-J00106 贵阳市清华中学 周子骏
#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll>mp;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    ll n,m,l=0;
    cin>>n>>m;
    set<ll>s;
    vector<ll>a(n+1),c(n+1,1);
    for(ll i=1;i<=n;i++){
    	cin>>a[i];}
    for(ll i=n;i>0;i--){
    	s.insert(a[i]);
    	if(s.size()+l!=n-i+1){
    		l++;
			c[i]==0;
			for(ll j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					break;
				}if(c[j]==0){
					for(ll k=j+1;a[k]!=a[j];k++){
						a[k]=1;
					}
				}
				c[j]=0;
			}
		}
		for(ll j=n;j>=i;j--){
    		if(c[j]!=0){
    			mp[a[j]]++;
				}
	}}
    for(ll j=1;j<=m;j++){
    	cout<<mp[j]<<' ';
	}
    return 0;

}
