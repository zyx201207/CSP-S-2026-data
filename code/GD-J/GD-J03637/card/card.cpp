#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],c[300010],b[300010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int o=0;
		for(int j=1;j<=n;j++){
			c[i]=0;
			b[i]=0;
		}
		for(int j=i;j<=n;j++){
			o++;
			if(c[a[j]]!=0 && c[a[j]]<o && b[c[a[j]]]==a[j]){
				o=c[a[j]];
			}else{
				b[o]=a[j];
				c[a[j]]=o;
			}
		}
		for(int i=1;i<=o;i++){
			d[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}

