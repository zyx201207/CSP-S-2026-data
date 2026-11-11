#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N=200005;

int a[N];
char c[N];
struct node{
	ll i;
	int id;
	char c;
}d[2*N];
bool cmp(node a,node b){
	return a.i<b.i;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int tot=0;
	ll lst=0;
	for(int i=1;i<=n;i++){
		d[++tot]={lst+1,0,c[i]};
		lst+=a[i];
	}
	lst=0;
	for(int i=n;i>=1;i--){
		d[++tot]={lst+1,1,c[i]};
		lst+=a[i];
	}
	sort(d+1,d+tot+1,cmp);
	d[tot+1].i=len+1;
	ll ans=0;
	ll i=1,pos=1;
	char x=0,y=0;
	while(i<=len){
		if(i==d[pos].i){
			if(d[pos].id==0)x=d[pos].c;
			else y=d[pos].c;
			++pos;
		}
		if(i==d[pos].i){
			if(d[pos].id==0)x=d[pos].c;
			else y=d[pos].c;
			++pos;
		}
		if(x!=y){
			ans+=(d[pos].i-i);
		}
		if(pos>tot)break;
		i=d[pos].i;
	}
	printf("%lld",ans/2);
	return 0;
}
