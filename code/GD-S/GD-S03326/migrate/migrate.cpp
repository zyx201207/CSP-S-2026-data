#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
#define gc getchar 
#define mn 2000005
#define pb push_back
#define pii pair<int,int>
#define pil pair<int,ll>
#define vp vector<pil>
#define vi vector<int> 
#define mp make_pair
#define sz size
#define fr first
#define se second
#define inf 0x3f3f3f3f3f3f3f3f
#define F(_,x,y) for(int _=x;_<=y;_++)
#define R(_,x,y) for(int _=x;_>=y;_--)
using namespace std;
int n,pr[mn],nx[mn];
ll d,x[mn],as,cl[mn],cr[mn];vi fb[mn];
ll rd(){
	ll x=0;char c=gc();int f=(c=='-');
	while(c<48)c=gc();while(c>47)x=x*10+c-48,c=gc();return x*(f?(-1):1);
}bool ok(int i,int j){return x[i]-x[j]<=d&&x[j]-x[i]<=d;}
bool fu(int i,int j){return j==nx[i]||j==pr[i];}
bool vl(int x){return 1<=x&&x<=n;}
ll sl(int x,int u,int v,int y){
	ll cntr=1;if(fu(u,y)&&nx[y]!=-1&&!ok(y+1,v)&&!ok(nx[y],y-1))cntr+=nx[y]-nx[y-1];
	if(fu(nx[y],y)&&nx[nx[y]]!=-1&&!ok(nx[y]-1,nx[nx[y]])&&!ok(nx[y],y-1)&&!ok(y+1,v)){
		cntr+=cr[nx[nx[y]]]+nx[nx[y]]-nx[nx[y]-1]-1;
	}
	ll cntl=1;if(fu(v,x)&&pr[x]!=-1&&!ok(x-1,u)&&!ok(pr[x],x+1))cntl+=pr[x+1]-pr[x];
	if(fu(pr[x],x)&&pr[pr[x]]!=-1&&!ok(pr[x]+1,pr[pr[x]])&&!ok(pr[x],x+1)&&!ok(x-1,u)){
		cntl+=cl[pr[pr[x]]]+pr[pr[x]+1]-pr[pr[x]]-1;
	}
//	cout<<x<<' '<<u<<' '<<v<<' '<<y<<' '<<cntl<<' '<<cntr<<'\n';
//	cout<<pr[x+1]-pr[x]<<'\n';
	return cntl*cntr; 
	
}
void wk(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	n=rd(),d=rd();F(i,1,n)x[i]=rd(),x[0]=x[1]-d-1,x[n+1]=x[n]+d+1,nx[n+1]=n+1;
	F(i,1,n){pr[i]=pr[i-1];while(x[i]-x[pr[i]]>d)pr[i]++;}
	R(i,n,1){nx[i]=nx[i+1];while(x[nx[i]]-x[i]>d)nx[i]--;}
	F(i,1,n)if(pr[i]!=-1)fb[pr[i]].pb(i);
	F(i,1,n)if(pr[i]==i)pr[i]=-1;F(i,1,n)if(nx[i]==i)nx[i]=-1;
	R(i,n,1){cr[i]=1;if(nx[i]!=-1)cr[i]+=nx[i]-i-1+cr[nx[i]]-(nx[nx[i]-1]-nx[i]);}
	F(i,1,n){cl[i]=1;if(pr[i]!=-1)cl[i]+=i-pr[i]-1+cl[pr[i]]-(pr[pr[i]+1]-pr[i]);}
//	F(i,1,n)cout<<cr[i]<<' ';cout<<'\n';
	F(x,1,n){int v=nx[x],u=v-1;if(!vl(v)||u==x)continue;
		for(auto y:fb[u])if(!ok(u-1,y)&&v!=y&&fu(y,u)&&fu(x,v)&&x<u&&u<v&&v<y)as+=sl(x,u,v,y);
	}printf("%lld\n",as);F(i,0,n+2)pr[i]=nx[i]=cl[i]=cr[i]=0,fb[i].clear();as=0;
}int main(){rd();int _=rd();while(_--)wk();}
/*
10 31746031746031745
-1000000000000000000 -777777777777777785 -555555555555555570 -333333333333333355 -111111111111111140 111111111111111075 333333333333333290 555555555555555505 777777777777777720 999999999999999935
10 222222222222222208
-999999999999999936 -777777777777777728 -555555555555555520 -333333333333333312 -111111111111111104 111111111111111104 333333333333333312 555555555555555520 777777777777777728 999999999999999936
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
10 1999999999999999970
-899999999999999986 -699999999999999989 -499999999999999992 -299999999999999995 -99999999999999998 99999999999999999 299999999999999996 499999999999999993 699999999999999990 899999999999999987

0 1
20 47
36 49 70 109 115 127 138 151 174 178 225 233 273 292 296 308 341 345 349 375
*/



