#include<bits/stdc++.h>
using namespace std;
long long n,k,ft[1000006],cnt;
struct node{
	int t,nx;
}v[2000006];
void add(int f,int t){
	v[++cnt]={t,ft[f]};
	ft[f]=cnt;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		cnt=0;
		for(int i=1;i<=n;i++)ft[i]=0;
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		long long x=(n/2+2+1)/2,y=(k+1)/2;
		cout<<(x-y+1)/2<<endl;
	}
} 
