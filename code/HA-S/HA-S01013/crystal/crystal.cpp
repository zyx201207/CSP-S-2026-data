#include<bits/stdc++.h>
#define getchar getchar_unlocked
using namespace std;
long long n,m,a[500005],ans;
long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
bool flag=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int l=1;l<=n;l++){
		a[l]=read();
		if(l!=1){
			if(a[l]-a[l-1]!=1)
				flag=0;
			if(a[l]-a[l-1]!=a[2]-a[1])
				flag2=0;
		}
	}
	if(flag){
		long long p=1,cnt=0;
		while(cnt+p<=m){
			cnt+=p;
			p++;
		}
		cout<<p<<endl;
		return 0;
	}
	if(flag2){
		long long delta_force=a[2]-a[1],p2=1,cnt2=0;
		while(cnt2+p2*delta_force<=m){
			cnt2+=p2*delta_force;
			p2++;
		}
		cout<<p2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long sum=0;
			for(int k=i;k<j;k++)
				sum+=(a[j]-a[k]);
			if(sum<=m)
				ans=max(ans,(long long)(j-i+1));
		}
	}
	printf("%lld",ans);
	return 0;
}
//O(n^3) wish to get 55 pts,special subtask A and B seems to be solved
//if i am a lucky dog,i will get 60pts
//God bless me
