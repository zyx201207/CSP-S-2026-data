#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
long long n,d,f[N],x[N];
ll c,t,ji[N],ans,ff[10000][10000];
char co[50];
void in(ll& a){
	a=0;
	char c=getchar();
	int fl=1;
	while(c<'0'||c>'9'){
		if(c=='-') fl=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') a*=10,a+=c-'0',c=getchar();
	a*=fl;
}
void out(__int128 b){
	int cnt=0;
	while(b) co[cnt++]='0'+b%10,b/=10;
	cout<<co<<'\n';
	for(int i=cnt-1;~i;i--) printf("%c",co[i]);
	if(!cnt) printf("0");
	printf("\n");
}
int dfs(int fr,int to,int s){
//	cout<<fr<<' '<<to<<'\n';
	if(fr==to) return 1;
	if(ff[fr][to]) return ff[fr][to];
	ll fd=f[fr],res=0;
	for(int i=fr+1;fd<=d&&i<=to;fd+=f[i],i++){
		int pd=dfs(i,to,s+1);
		if(res==-1) return ff[i][to]=-1;
		res+=pd;
		if(res>2) return ff[i][to]=-1;
	}
	return ff[fr][to]=res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	in(c),in(t);
	if(c==11||c==12||c==0){
		while(t--){	
			in(n);in(d);
			for(int i=1;i<=n;i++) in(x[i]);
			if(n<3) printf("0\n");
			else{
				ll k=d/(x[2]-x[1])-1;
				if(k>0) printf("%lld\n",(n-k*2-3)>0?(n-k*2-1):0);
				else printf("0\n");
			}
		}
	}
	return 0;
}
/*13 2
4 15
1 3 4 5
4 15
-1 3 4 5*/
