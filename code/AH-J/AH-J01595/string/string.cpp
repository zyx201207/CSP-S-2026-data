#include<bits/stdc++.h>
using namespace std;
char a[300005];
long long b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,j,k,ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld %c",&b[i],&a[i]);
	i=1,j=n;
	while(i<j){
		if(b[i]<=b[j])
			k=b[i],b[j]-=b[i],b[i]=0;
		else
			k=b[j],b[i]-=b[j],b[j]=0;
		if(a[i]!=a[j])	
			ans+=k;	
		if(b[i]==0)
			i++;
		if(b[j]==0)
			j--;
	}
	printf("%lld",ans); 
	return 0;
}
