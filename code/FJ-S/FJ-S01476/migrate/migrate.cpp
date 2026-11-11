#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N=5007;
void in(ll &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}
void int_in(int &k){
	k=0;
	int f=1;
	char c=getchar();
	while(!((c>='0'&&c<='9')||c=='-')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	k*=f;
	return;
}

int n;
ll d,x[N],p[N];
int f[N],v[N];
void solve(int c){
	int_in(n);
	in(d);
	ll ans=0;
	for(int i=1;i<=n;i++) in(x[i]);
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++) v[k]=0,f[k]=n+5;
		f[i]=0;
		v[i]=1;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int h=q.front();
			q.pop();
			for(int k=h+1;k<=n;k++){
				if(x[k]-x[h]>d) break; 
				if(f[k]>f[h]+1){
					if(!v[k]) q.push(k);
					v[k]=v[h];
					f[k]=f[h]+1;
				}else if(f[k]==f[h]+1){
					v[k]+=v[h];
				}
			}
		}
		for(int k=i;k<=n;k++) if(v[k]==2) ans++;
	}
	
	printf("%lld\n",ans);
	return; 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int_in(c);int_in(t);
	while(t--) solve(c);
	return 0;
}
