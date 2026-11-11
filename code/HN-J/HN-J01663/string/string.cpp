#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long l=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
		scanf("%d %c\n",&a[i],&c[i]),l+=a[i];
	scanf("%d %c",&a[n],&c[n]),l+=a[n];
	int	R=1,L=n/1;
	l=l/2;
	l+=l%2;
	for(;l>0;){
		if(a[R]>=a[L]){
			if(c[R]!=c[L]){
				a[R]-=a[L];
				if(l>=a[L])
					l-=a[L],ans+=a[L];
				else
					ans+=l,l=0;
				L--;
			}
			else{
				a[R]-=a[L];
				if(l>=a[L])
					l-=a[L];
				else
					l=0;
				L--;
			}
		}
		else{
			if(c[R]!=c[L]){
				a[L]-=a[R];
				if(l>=a[R])
					l-=a[R],ans+=a[R];
				else
					ans+=l,l=0;
				R++;
			}
			else{
				a[L]-=a[R];
				if(l>=a[R])
					l-=a[R];
				else
					l=0;
				R++;
			}
		}
		if(L==R)
			l=0;
	}
	printf("%lld",ans);
}
