#include<bits/stdc++.h>
using namespace std;
int n;
long long a1[200005],sum,maxn;
char a2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld ",&a1[i]);
		scanf("%c",&a2[i]);
	}
	int l=1,r=n;
	while(l<r){
		if(a2[l]!=a2[r]){
			sum=min(a1[l],a1[r]);
			a1[l]-=sum,a1[r]-=sum;
			maxn+=sum;
		}else{
			sum=min(a1[l],a1[r]);
			a1[l]-=sum,a1[r]-=sum;
		}
		if(a1[l]==0) l++;
		if(a1[r]==0) r--;
    }
	printf("%lld",maxn);
	return 0;
} 
