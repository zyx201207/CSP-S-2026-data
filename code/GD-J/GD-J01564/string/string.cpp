#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],n,ans=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
	}
	ll nown=1,p=0;
	for(int i=n;nown<i;){
		if(a[i]>a[nown]){
			if(c[i]!=c[nown]){
				ans+=a[nown];
			}
			a[i]-=a[nown];
			nown++;
		}else if(a[i]<a[nown]){
			if(c[i]!=c[nown]){
				ans+=a[i];
			}
			a[nown]-=a[i];
			i--;
		}else{
			if(c[i]!=c[nown]){
				ans+=a[nown];
			}
			nown++;i--;
		}
	}
	printf("%lld",ans);
}
