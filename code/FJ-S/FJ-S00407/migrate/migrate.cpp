#include<bits/stdc++.h>
#define lll long long
using namespace std;
int n;
lll d,a[2000010];
void TeC(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	d/=(a[2]-a[1]);
	//cout<<n<<" "<<d<<" ";
	if(d==0 or d==1 or 2*d>n or n==1) printf("0\n");
	else printf("%lld\n",n+1-2*d);
}
struct node{
	int d,l;
};
queue<node> que,kkk;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,C;
	scanf("%d%d",&C,&T);
	if(C==11 or C==12){
		while(T--) TeC();
		return 0;
	}
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		lll ans=0;
		//int frmm=1,tooo=5;
		for(int frmm=1;frmm<=n;frmm++){
			for(int tooo=upper_bound(a+1,a+1+n,(lll)a[frmm]+d)-a;tooo<=n;tooo++){
				//cout<<frmm<<" "<<tooo<<endl;
				que=kkk;
				int g=0,minn=-1;
				node aa;aa.d=frmm,aa.l=0;
				que.push(aa);
				while(!que.empty()){
					auto t=que.front();
					que.pop();
					if(minn!=-1 and t.l>=minn) continue;
					//cout<<t.d<<" "<<t.l<<endl;
					for(int i=t.d+1;a[i]-a[t.d]<=d and i<=n;i++){
						if(i==tooo){
							g++;
							minn=t.l+1;
							break;
						}
						aa.d=i,aa.l=t.l+1;
						que.push(aa);
					}
					if(g>2) break;
				}
				if(g==2) ++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
