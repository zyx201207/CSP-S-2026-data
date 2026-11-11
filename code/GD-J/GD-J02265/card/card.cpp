#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[500010],c[500010],d[500010];
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int u=n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	d[i]=a[i];
}
	int v=0;
	while(u--){
		for(int i=1+v;i<=n;i++){
			b[a[i]]++;
			c[a[i]]++;			
			if(b[a[i]]>1&&i!=n&&a[i]!=0){
				for(int j=i-1;j>=0;j--){
					c[a[j]]--;
					b[a[j]]--;
					a[j]=0;						
					if(a[j]==a[i])break;																										
				}
			}
		}
		for(int i=1;i<=m;i++){
			b[i]=0;	
		}
		v++;
		for(int i=1;i<=n;i++)a[i]=d[i];
}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
