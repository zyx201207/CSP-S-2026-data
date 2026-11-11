#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500009],s[500009];
bool p[500009]={true};
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++)
	    {   
	        p[j]=1;
	    	for(int k=j;k>=i;k++)
	    	if(a[j]==a[k]&&p[j]&&p[k])
	    	  for(int u=k;u<j;u++)
	    	     p[u]=0;
		}
		int h=0;
		for(int j=i;j<=n;j++)
		  if(p[j]) h+=a[j];
		s[h]++;
	}
	for(int i=1;i<=n;i++) 
	printf("%d",s[i]);  
	return 0;
}
