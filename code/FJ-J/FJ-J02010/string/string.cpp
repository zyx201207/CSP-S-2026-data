#include<bits/stdc++.h>
using namespace std;
int n,j=1,k;
long long ans,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	k=n;
	if(n%2)
		n=n/2+1;
	else
		n=n/2;
	while(j!=k&&j<=n){
		if(c[j]!=c[k]){
			if(a[j]>a[k]){
				a[j]-=a[k];
				ans+=a[k];
				k--;
			}
			else if(a[j]<a[k]){
				a[k]-=a[j];
				ans+=a[j];
				j++;
			}
			else{
				ans+=a[j];
				j++;
				k--;
			}
		}
		else{
			if(a[j]>a[k]){
				a[j]-=a[k];
				k--;
			}
			else if(a[j]<a[k]){
				a[k]-=a[j];
				j++;
			}
			else{
				j++;
				k--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
