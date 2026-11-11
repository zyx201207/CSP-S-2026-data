#include<bits/stdc++.h>
using namespace std;
struct ycdf{
	long long a;
	char c;
}a[100086];
long long sum[100086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,t=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long s;
		char c;
		scanf("%lld %c",&s,&c);
		if(a[t].c==c){
			a[t].a+=s;
			sum[t]+=s;
		}
		else{
			t++;
			a[t]={s,c};
			sum[t]=sum[t-1]+s;
		}
	}
	long midr=sum[t]/2+1,midl=sum[t]/2;
	if(sum[t]%2){
		midr++;
	}
	long mrp,rsy,mlp,lsy;
	for(int i=1;i<=t;i++){
		if(sum[i-1]<midr and midr<=sum[i]){
			mrp=i;
			rsy=sum[i]-midr+1;
		}
		if(sum[i-1]<midl and midl<=sum[i]){
			mlp=i;
			lsy=midl-sum[i-1];
		}
	}
	long ans=0;
	while(mrp<=t or mlp>=0){
		if(a[mrp].c==a[mlp].c){
			ans+=abs(rsy-lsy);
			if(rsy<lsy){
				lsy-=rsy;
				mrp++;
				rsy=a[mrp].a;
			}
			else if(rsy>lsy){
				rsy-=lsy;
				mlp--;
				lsy=a[mlp].a;
			}
			else{
				mrp++;
				rsy=a[mrp].a;
				mlp--;
				lsy=a[mlp].a;
			}
		}
		else{
			ans+=min(rsy,lsy);
			if(rsy<lsy){
				lsy-=rsy;
				mrp++;
				rsy=a[mrp].a;
			}
			else if(rsy>lsy){
				rsy-=lsy;
				mlp--;
				lsy=a[mlp].a;
			}
			else{
				mrp++;
				rsy=a[mrp].a;
				mlp--;
				lsy=a[mlp].a;
			}
		}
	}
	cout<<ans;
}
