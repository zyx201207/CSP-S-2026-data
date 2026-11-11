#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long x,y,n,m,c[N],s,a[N],b[N],ma=-1,z[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]>0&&b[a[j]]<=s&&z[b[a[j]]]==a[j]){
				s=b[a[j]];
			}else {
				b[a[j]]=++s;
				z[s]=a[j];
			}
		}
		for(int j=1;j<=s;j++){
			c[z[j]]++;
		}
	}
	for(int j=1;j<=m;j++)cout<<c[j]<<" ";
	return 0;
}
