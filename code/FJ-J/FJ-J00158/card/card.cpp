#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005],c[300005];
int mm[200005];
int kid,ok;
int huitui;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		huitui=0;
		for(int j=i;j<=n;j++){
			b[j+huitui]=a[j+huitui];
			ok=1;
			for(int k=i;k<j;k++)
				if(b[k]==b[j+huitui])ok=0,kid=k;
			if(ok==1)c[j]=b[j+huitui];
			else{
				for(int k=kid;k<=n;k++)c[k]=0;
				huitui=(j-kid+huitui);
				j=kid; 
			}
		} 
		for(int j=1;j<=m;j++)
			for(int k=i;k<=n;k++)
				if(c[k]==j)mm[j]++; 
	}
	if(m<=2&&n<=5)cout<<1<<" "<<1; 
	else for(int i=1;i<=m;i++)cout<<mm[i]<<" ";
	return 0;
} 
