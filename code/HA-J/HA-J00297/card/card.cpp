#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
ll t[500010];
ll v[500010];
ll check(int o){
	for(int i=1;i<=n;i++){
		if(t[i]==o){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ll p=check(a[j]);
			if(p!=0){
				for(int k=p;k<=n;k++){
					t[k]=0;
				}
			}
			t[j]=a[j];
		}
		for(int j=1;j<=n;j++){
			if(t[j]>0){
				v[t[j]]++;
				t[j]=0;
			}
			else{
				continue;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
