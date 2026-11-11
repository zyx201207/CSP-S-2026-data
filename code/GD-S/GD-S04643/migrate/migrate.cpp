#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5050;
int c,n,res;
ll m,ans;
ll a[N];
void cal(int s,int t,int sum,int cnt){
	if(cnt>=sum&&s!=t)return;
	if(cnt==sum&&s==t)ans++;
	if(ans>2)return;
	for(int i=s+1;i<=t;i++){
		if(a[i]-a[s]>m)break;
		cal(i,t,sum,cnt+1);
	}
}
void work(){
	res=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i+2<=n;i++)
		for(int j=i+2;j<=n;j++){
			int cnt=0,p=i,k;
			for(k=i;k<j;k++){
				if(a[k+1]-a[k]>m)break;
				if(a[k+1]-a[p]>m){
					cnt++;
					p=k;
				}
			} 
			if(a[k]-a[k-1]>m)break;
//			cout<<i<<" "<<j<<" "<<cnt+1<<"\n";
			ans=0;
			cal(i,j,cnt+1,0);
//			if(i==1&&j==5)cout<<ans<<"\n";
			if(ans==2){
				res++;
//				cout<<i<<" "<<j<<"\n";
			}
		}
	printf("%d\n",res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;scanf("%d%d",&c,&T);
	while(T--)work();
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
8 3
0 1 2 4 8 10 11 13

c
*/
