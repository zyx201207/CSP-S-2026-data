#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],w;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),cin>>c[i];
	for(int i=1,j=n;i<=j;){
		if(c[i]==c[j]){
			if(a[i]>a[j])
				a[i]-=a[j],j--;
			else if(a[i]<a[j])
				a[j]-=a[i],i++;
			else 
				i++,j--;
		}
		else{
			if(a[i]>a[j])
				w+=a[j],a[i]-=a[j],j--;
			else if(a[i]<a[j])
				w+=a[i],a[j]-=a[i],i++;
			else 
				w+=a[i],i++,j--;
		}
	}
	printf("%lld",w);
	return 0;
} 
