#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int b[N],bb[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=i;
	}
	int len=n;
	long long sum=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=len;j++){
			if(((a[b[j]]>>i)&1)==1) cnt++;
		}
		if(cnt<m) continue;
		sum+=(1<<i);
		if(cnt<len){
			int l=0;
			for(int j=1;j<=len;j++){
				if(((a[b[j]]>>i)&1)==1){
					bb[++l]=b[j];
				}
			}
			for(int j=1;j<=l;j++) b[j]=bb[j];
			len=l;
		}
	}
	printf("%lld",sum);
	return 0;
}