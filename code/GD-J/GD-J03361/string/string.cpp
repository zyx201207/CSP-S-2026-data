#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll ans;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d %c",&a[i],&c[i]);
	for(int i=1,j=n;i<=j;){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

