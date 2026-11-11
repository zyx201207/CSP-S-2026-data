#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[500010],b[300010],c=1,d[300010],e=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(e<=c){
				if(a[j]==b[e]){
					c=1;
					continue;
				}
				e++;
			}
			e=1;
			b[c]=a[j];
			c++;
		}
		for(int j=1;j<c;j++){
			d[b[j]]++;
		}
		c=1;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
} 
