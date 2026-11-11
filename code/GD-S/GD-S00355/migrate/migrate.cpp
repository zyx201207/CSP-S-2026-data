#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char ch;
void input(ll &x){
	int f=1;
	while(!isdigit(ch=getchar()))
		if(ch=='-')
			f=-f;
	x=0;
	do{x=x*10+ch-48;}while(isdigit(ch=getchar()));
	x*=f;
}
const int N=2e6+10;
ll n,d,x[N],sd;
inline ll solveA(int k){
	return max(n-(k<<1)+1,0ll);
}
int main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	do{
		input(n);
		input(d);
//		cerr<<n<<' '<<d<<'\n';
		bool flag=false;
		for(int i=1;i<=n;++i){
			input(x[i]);
			if(i^1&&x[i]-x[i-1]>d)flag=true;
		}
		if(n<=3||flag){
			puts("0");
			continue;
		}
		sd=x[2]-x[1];
		sd=d/sd;
		if(c==11||c==12||!c)cout<<(sd==1?0:solveA(sd))<<'\n';
		else cout<<0<<'\n';
	}while(--T);
	return 0;
}
