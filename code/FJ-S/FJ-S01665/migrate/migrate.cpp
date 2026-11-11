#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f 
#define endl '\n'
int n,m;
int d;
int a[202020];
int b[202020];
int c,t;
int ans=0;
int bns=0,cnt=0;
void s(int y,int r)
{
if(y==d){
	if(r<bns){
		bns=r;
		cnt=1;
	}else if(r==bns)cnt++;
	return ;
	}for(int i=d;i>y;i--){
	if((b[i]-b[y])<=m){
			s(i,r+1);		}
	}

	
}

signed main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
int dx,dy;
ans=0;
cin>>dx>>dy;
n=dx;
m=dy;
int x;
	for(int i=1;i<=n;i++){
	
		cin>>x;
		a[x]=i;
		b[i]=x;
		}
	for(int i=1;i<=n;i++){
	for(int j=1;j<i;j++){
		
		d=i;
		bns=INF;
	   cnt=0;
		
			s(j,0);
			
			if(cnt==2){ans++; 
			}   
	}
	}cout<<ans<<endl;
}
return 0;
}

