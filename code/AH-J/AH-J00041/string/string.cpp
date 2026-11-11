#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],n;
long long sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]) sum+=min(a[i],a[j]);
		if(a[i]==a[j]) i++,j--;
		else if(a[i]<a[j]) a[j]-=a[i++];
		else a[i]-=a[j--];
	}
	printf("%lld\n",sum);
	return 0;
}
