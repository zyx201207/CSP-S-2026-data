#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],l=1,r;
char ch[MAXN];
long long int b[MAXN],k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	r=n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&ch[i]);
	}
	while(l<r){
		int mi=min(a[l],a[r]);
		a[l]-=mi;
		a[r]-=mi;
		if(ch[l]!=ch[r])k+=1LL*mi;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	printf("%lld",k);
	return 0;
}
