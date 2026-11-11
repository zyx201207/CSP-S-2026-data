#include<iostream>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	} 
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=1,ll=a[1];
	int r=n,rr=a[n];
	long long ans=0;
	while(l<r){
		if(ll>rr){
			if(c[l]!=c[r]) ans+=rr;
			ll-=rr;
			r--;
			rr=a[r];
		}else{
			if(c[l]!=c[r]) ans+=ll;
			rr-=ll;
			l++;
			ll=a[l];
		}
	}
	printf("%lld",ans);
	return 0;
}

