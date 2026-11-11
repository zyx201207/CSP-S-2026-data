#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[500010],t[300010],c[300010],s[300010],k[300010],js;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			t[j]=0;
			s[j]=1e9;
		}
		js=0;
		for(j=i;j<=n;j++){
			t[a[j]]++;
			js++;
			if(t[a[j]]==2){
				js=min(js,s[a[j]]);
				t[a[j]]=1;
			}
			s[a[j]]=js;
			k[js]=a[j];
		}
		for(j=1;j<=js;j++){
			c[k[j]]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
