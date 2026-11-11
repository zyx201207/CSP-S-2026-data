#include<bits/stdc++.h>
using namespace std; 
int n,m,a[100010],b[100010],k[3]={0,0,0},c[3]={0,0,0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)b[j]=a[j];
		c[1]=c[2]=c[3]=0;
		for(int j=i;j<=n;j++){
				if(c[1]==b[j])c[2]=0;
				else if(c[2]==b[j])continue;
				else if(c[1]>0)c[2]=b[j];
				else c[1]=b[j];
				
		}
	
		k[c[1]]++;
		k[c[2]]++;
	}
	cout<<k[1]<<' '<<k[2];
    return 0;
}
