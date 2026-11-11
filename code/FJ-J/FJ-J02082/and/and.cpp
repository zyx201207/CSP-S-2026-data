#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,k;
int ans=0;
int m=0;
int bns=0;
int a[201020];
int b[202020];
int vis[202020];
void aa(int x,int y){
	int dx=0;
	bns=0;
	int dy=0;
	int xy=0;
	int u=0;
while(x){
dx*=10;
dx+=x%2;
x/=2;
}
while(y){
	dy*=10;
	dy+=y%2;
	y/=2;
}
if(dx>dy){
while(dx){
	int q=dx%10;
	int qi=dy%10;
	if(q==0||qi==0){
		xy*=10;
	}else {
		xy*=10;xy+=1;
		
	}
	u++;
	dx/=10;
	dy/=10;}}
	else{
while(dy){
int q=dx%10;
int qi=dy%10;
if(q==0||qi==0){
	xy*=10;
}else {
	xy*=10;
	xy+=1;
}dy/=10;u++;dx/=10;
}}
int q=xy%10;
m+=q;xy/=10;
while(xy){
	 q=xy%10;
	for(int i=1;i<=u;i++){
		q*=2;
	}m+=q;xy/=10;u--;
}bns+=m;return ;

}

void ss(int x){
	if(x>k){
	int cns=a[1];
	for(int i=1;i<k;i++){
		aa(cns,b[i+1]);cns=bns;
	}
	ans=max(ans,cns);return;
	}
for(int i=1;i<=n;i++){
if (vis[i]==0)
{b[x]=a[i];
vis[i]=1;
ss(x+1);
vis[i]=0;
}
}
}
signed main(){
//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
ss(1);
cout<<ans;

return 0;
} 

