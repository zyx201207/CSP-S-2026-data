//GZ-J00383 邓智豪 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+500;

int n;
int a[MAXN];
char c[MAXN];
unsigned long long L;
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %c",a+i,c+i);
	}
	for(int i=0,j=n;i<j;i++){
		if(c[i]!=c[j-1]){
			if(a[i]<a[j-1]){
				c[i]=c[j-1];
				a[j-1]-=a[i];
				ans+=a[i];
			}else{
				c[j-1]=c[i];
				a[i]-=a[j-1];
				ans+=a[j-1];
				j--;
				i--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
