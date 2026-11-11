#include <bits/stdc++.h>
using namespace std;
struct st {
	long long l,r;
	char f;
}v[200005];
int n,a[200005];
char c[200005];
long long s,len;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		v[i].l=len+1,v[i].f=c[i];
		len+=a[i];
		v[i].r=len;
	}
	long long k=n,i=1;
	while(i<k){
		if(v[i].f!=v[k].f){
			if(a[i]<=a[k]){
				s+=a[i];
				a[k]-=a[i];
				i++;
			}
			else {
				s+=a[k];
				a[i]-=a[k];
				k--;
			}
		}
		else {
			if(a[i]<=a[k]){
				a[k]-=a[i];
				i++;
			}
			else {
				a[i]-=a[k];
				k--;
			}
		}
	}
	printf("%lld",s);
	return 0;
} 
