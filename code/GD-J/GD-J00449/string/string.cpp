#include<iostream>
#include<cstring> 
#include<cstdio>
using namespace std;
int n;
long long sum[200005];
char c[200005];
long long cnt[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>sum[i]>>c[i];
		sum[i]+=sum[i-1];
	}
	int x=0,l=n+1,r=n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(sum[i]*2<=sum[n]){
			while(sum[n]-sum[l-1]<sum[i]){
				l--;
				cnt[int(c[l]-'a')]+=(sum[l]-sum[l-1]);
			}
			long long nl=sum[n]-sum[i]+1;
			while(sum[n]-sum[r]<sum[i-1]){
				cnt[int(c[r]-'a')]-=(sum[r]-sum[r-1]);
				r--;
			}
			long long nr=sum[n]-sum[i-1];
//			cout<<l<<' '<<r<<'|'<<nl<<' '<<nr<<endl; 
			if(nl!=sum[l-1]+1){
				cnt[int(c[l]-'a')]-=(nl-sum[l-1]-1);
			}
			if(nr!=sum[r]){
				cnt[int(c[r+1]-'a')]+=(nr-sum[r]);
			}
			ans=ans+sum[i]-sum[i-1]-cnt[int(c[i]-'a')];
			if(nl!=sum[l-1]+1){
				cnt[int(c[l]-'a')]+=(nl-sum[l-1]-1);
			}
			if(nr!=sum[r]){
				cnt[int(c[r+1]-'a')]-=(nr-sum[r]);
			}
		}else{
			if(sum[i]*2ll-sum[n]<sum[i]-sum[i-1]){
				x=i;
			}
			break;
		}
	}
	if(x){
		ans=ans+sum[x]-sum[x-1]-(sum[x]*2ll-sum[n]);
		int l=x;
		while(sum[n]-sum[l+1]>=sum[x-1]&&l+1<=n){
			l++;
			if(c[l]==c[x])ans=ans-(sum[l]-sum[l-1]);
		}
		if(sum[n]-sum[l]>sum[x-1]&&c[l+1]==c[x]){
			ans=ans-((sum[n]-sum[l])-sum[x-1]);
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
3
5 a
1 b
1 a 

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
