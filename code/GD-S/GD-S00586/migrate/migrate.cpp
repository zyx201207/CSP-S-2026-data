// Let's make some n^2 (40 pts)
// Confirmed 40 pts?
#include<iostream>
using namespace std;
const int N=2e6+10;
int c,T,n,nxt[N],dul[N];
using ll=long long;
ll p[N],res,d;
void run(){
	cin>>n>>d;
	res=0;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int r=1,td=1;r<=n;r++){
		dul[r]=nxt[r]=0;
		td=1;
		for(int i=r-1,rb=r;i;i--){
			while(p[rb]-p[i]>d)rb--;
			if(rb==i){
				td=i+1;
				break;
			}
			dul[i]=dul[rb],nxt[i]=rb;
			if(dul[i]==-1)continue;
			if(nxt[rb]){
				if(rb==i+1)continue;
				if(p[nxt[rb]]-p[rb-1]>d)continue;
				dul[i]=(dul[i]?-1:1);
				if(rb>i+2 and p[nxt[rb]]-p[rb-2]<=d)dul[i]=-1;
			}
		}
		for(int i=td;i<=r;i++)res+=(dul[i]==1);
	}
	cout<<res<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--)run();
}