#include<bits/stdc++.h>
using namespace std;
int n;
int const MAXN=10005;
long long a[MAXN];
char c[MAXN];
long long cnt=1;
char w[10000005];
long long sum=0;//sum ÎªÌæ»»´ÎÊý 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf("%s",&c[i]);
		for(long long j=1;j<=a[i];j++){
			w[cnt]=c[i];
			cnt++;
		}
	}
	for(long long i=1;i<=cnt/2;i++){
		if(w[i]!=w[cnt-i])sum++;
	}
	cout<<sum;
	return 0;
}
