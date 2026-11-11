#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,tot,cnt;
long long a[N],d;
void A(){
	while(t--){
		scanf("%d%lld",&n,&d);	
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n<=3||d<1ll*(a[2]-a[1])){printf("%d\n",0);continue;}
		long long x=2*d/(a[2]-a[1]);
		if(x==2){printf("%d\n",0);continue;}
		printf("%d\n",(x<=1ll*n)?n-(int)x+1:0);
	}
}
void B(){
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int sum=0,x;
		long long ans=0;
		a[0]=a[1],a[n+1]=a[n];
		for(int i=1;i<=n;i++)
		    if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
			    if(i<=2||i>=n-1) sum+=3;
			    else sum++,x=i;
			}
		if(n==4&&sum==6){printf("%d\n",1);continue;}
		if(sum>2||n<=3){printf("%d\n",0);continue;}
		for(int l1,l2,r1,r2,op=0;op<2;op++){
			r1=upper_bound(a+1,a+1+n,a[x-2+op]+d)-a;
			r2=upper_bound(a+1,a+1+n,a[x-1+op]+d)-a-1;
			l1=lower_bound(a+1,a+1+n,a[x+op]-d)-a;
			l2=lower_bound(a+1,a+1+n,a[x+1+op]-d)-a-1;
			ans+=1ll*(r2-r1+1)*(l2-l1+1);
	    }
		printf("%lld\n",ans);
	}
}
void dfs1(int st,int ed,int num,long long res){
	if(st==ed){cnt=min(cnt,num); return;}
	if(num>=cnt) return ;
	if(a[st+1]-a[st]>d) return;
	if(a[st+1]-a[st]<=res) dfs1(st+1,ed,num,res-(a[st+1]-a[st]));
	dfs1(st+1,ed,num+1,d-a[st+1]+a[st]);
}
void dfs2(int st,int ed,int num,long long res){
	if(num>cnt) return ;
	if(st==ed){tot++; return;}
	if(a[st+1]-a[st]>d) return;
	if(a[st+1]-a[st]<=res) dfs2(st+1,ed,num,res-(a[st+1]-a[st]));
	dfs2(st+1,ed,num+1,d-(a[st+1]-a[st]));
}
void work(){
	while(t--){
		int ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=n,tot=0;
				dfs1(i,j,1,d),dfs2(i,j,1,d);
				if(tot==2) ans++;
			} 
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=4){work();return 0;} 
	if(c==11||c==12){A();return 0;}
	if(c==13||c==14){B();return 0;}
	return 0;
}
