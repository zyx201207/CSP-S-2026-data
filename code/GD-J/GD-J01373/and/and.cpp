#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int a[maxn],pre[maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	int max_num=-1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		max_num=max(max_num,a[i]);
		pre[i]=pre[i-1]&a[i];
	}
	if(m==1){
		printf("%lld",max_num); 
		return 0;
	}
	else if(m==n){
		printf("%lld",pre[m]);
		return 0;
	}
	else if(m==2){
		max_num=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				
				max_num=max(max_num,a[i]&a[j]);
			}
		}
		printf("%lld",max_num);
	}
	else{
		sort(a+1,a+n+1);
		printf("%lld",a[m-1]&max_num);
	}
	return 0;
}
