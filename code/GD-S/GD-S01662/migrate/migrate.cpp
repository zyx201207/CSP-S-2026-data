#include<bits/stdc++.h>
#define ll long long
#define Pii pair<int,int>
#define Pil pair<int,ll>
#define Fi first
#define Se second
using namespace std;
namespace IO{
	bool Isdigit(char c){return c>='0'&&c<='9';}
	template<typename T>inline void read(T &x){
		char c=getchar();bool f=0;x=0;
		while(!Isdigit(c)){if(c=='-')f=1;c=getchar();}
		while(Isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
		x=f?-x:x;
	}
}
using namespace IO;
const int N=2e6+10;
int C,T,n,Dis[N],f[N];
ll D,a[N];
void Update(int Pos,int F){
	if(F==-1||f[Pos]==-1)
		return f[Pos]=-1,void();
	f[Pos]+=F;
	if(f[Pos]>2)f[Pos]=-1;
}
void Solve(){
	read(n),read(D);
	for(int i=1;i<=n;i++)read(a[i]);
	ll Res=0;
	for(int i=1;i<n;i++){
		f[i]=1,Dis[i]=0;
		for(int j=i+1;j<=n;j++)f[j]=-1;
		for(int j=i+1,l=i;j<=n;j++){
			while(a[l]+D<a[j])l++;
			if(l==j)break;
			f[j]=0,Dis[j]=Dis[l]+1;
			Update(j,f[l]);
			if(l+1<j&&Dis[l+1]==Dis[l])Update(j,f[l+1]);
			if(l+2<j&&Dis[l+2]==Dis[l])f[j]=-1;
			Res+=f[j]==2;
		}
	}
	printf("%lld\n",Res);
}
void Solve_1(){
	read(n),read(D);
	for(int i=1;i<=n;i++)read(a[i]);
	ll Res=0;int Lx=lower_bound(a+1,a+n+1,a[1]+2*D)-a-5;
	for(int i=max(Lx,3);i<=n;i++){
		int r=upper_bound(a+1,a+n+1,a[1]+D)-a-1;
		int l=lower_bound(a+1,a+n+1,a[i]-D)-a;
		if(r==l+1)Res+=n-i+1;
		if(r<=l)break;
	}
	printf("%lld\n",Res);
}
void Solve_2(){
	read(n),read(D);
	for(int i=1;i<=n;i++)read(a[i]);
	ll Res=0;
	for(int i=1,l,r,R;i<n;i++){
		int Lst=i,Pos=i,Fl=0;
		while(Pos<n){
			if(Lst==Pos&&Fl){
				l=upper_bound(a+1,a+n+1,a[Pos-1]+D)-a;
				r=upper_bound(a+1,a+n+1,a[Pos]+D)-a-1;
				if(l>r)break;
				Res+=r-l+1;
				Lst=Pos=r;
			}
			else if(Lst==Pos&&!Fl){
				l=Pos==i?i+1:upper_bound(a+1,a+n+1,a[Pos-1]+D)-a;
				r=upper_bound(a+1,a+n+1,a[Pos]+D)-a-1;
				if(l>r)break;
				Lst=max(l,r-1),Pos=r;
			}
			else if(Lst<Pos&&!Fl){
				l=upper_bound(a+1,a+n+1,a[Lst-1]+D)-a;
				R=upper_bound(a+1,a+n+1,a[Lst]+D)-a-1;
				r=upper_bound(a+1,a+n+1,a[Pos]+D)-a-1;
				if(l>r)break;
				if(l<=R){
					Res+=R-l+1;
					Lst=max(R+1,r-1),Pos=r;
					if(R==r)Lst=r,Fl=1;
				}
				else Lst=max(l,r-1),Pos=r;
			}
		}
	}
	printf("%lld\n",Res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(C),read(T);
	while(T--){
		if(C>=11&&C<=12)Solve_1();
		else if(C>=13&&C<=18)Solve_2();
		else Solve();
	}
}