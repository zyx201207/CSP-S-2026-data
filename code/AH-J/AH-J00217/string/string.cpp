#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char s;
}a[200010];
long long n,m,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	char wwww=0;
	int www=1;
	for(int i=1;i<=n;i++){
		++m;
		scanf("%lld",&a[m].x);
		cin>>a[m].s;
		if(i==1)wwww=a[m].s;
		else if(wwww!=a[m].s)www=0;
		if(a[m-1].s==a[m].s){
			a[m-1].x+=a[m].x;
			m--;
		}
	}
	if(www==1){
		printf("0");
		return 0;
	}
	for(int i=1,j=m;i<j;i++,j--){
		if(a[i].s==a[j].s){
			if(a[i].x==a[j].x)continue;
			else{
				if(a[i].x>a[j].x){
					ans+=a[i].x-a[j].x;
					a[j-1].x--;
				}else{
					ans+=a[j].x-a[i].x;
					a[i+1].x--;
				}
			}
		}else{
			if(a[i].x==a[j].x)ans+=a[i].x;
			else{
				if(i+1==j&&m%2==0){
					ans+=min(a[i].x,a[j].x);
				}else if(a[i].x>a[j].x){
					ans+=a[i].x;
					a[j-1].x-=(a[i].x-a[j].x);
				}else{
					ans+=a[j].x;
					a[i+1].x-=(a[j].x-a[i].x);
				}
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
