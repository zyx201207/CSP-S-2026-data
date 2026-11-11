#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[300010],b[500010],c[500010],d[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
		cin>>a[i];
	}	
	for(int i=1 ; i<=n ; i++){
		long long ans=0;
		for(int j=i ; j<=n ; j++){
			ans++;
			if(b[a[j]]<=ans&&d[b[a[j]]]==a[j]){
				ans=b[a[j]];
			}else{
				d[ans]=a[j];
				b[a[j]]=ans;
			}
		}
		for(int j=1 ; j<=ans ; j++){
			t[d[j]]++;
		}
		for(int j=1 ; j<=ans ; j++){
			d[j]=0;
		}
	}
	for(int i=1 ; i<=m ; i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
