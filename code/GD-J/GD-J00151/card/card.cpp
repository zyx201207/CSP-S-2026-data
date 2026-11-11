#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],to,b[500010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		to=1;
		for(int j=i;j<=n;j++){
			a[to]=b[j];
			to++;
			for(int p=to-2;p>0;p--){
				if(a[p]==b[j]){
					to=p+1;
					break;
				}
			}
		}
		for(int j=1;j<to;j++){
			c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
