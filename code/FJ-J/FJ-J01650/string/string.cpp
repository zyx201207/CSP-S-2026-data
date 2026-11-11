#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,ans,tmp;
char tmps[2];
int len;
char arr[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;++i){
		scanf("%lld %s",&tmp,&tmps);
		for(int j=len;j<tmp+len;++j)arr[j]=tmps[0];
		len+=tmp;
	}
	int i=0,j=len-1;
	while(i<=j){
		if(arr[i]!=arr[j])++ans;
		++i;
		--j; 
	}
	printf("%lld",ans);
	return 0;
} 

