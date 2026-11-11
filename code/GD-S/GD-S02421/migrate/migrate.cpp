#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//#define int long long
//#define cerr if(0)clog
int ls[2002000];
bool v[2002000];
int ljmp[2002000];
int rjmp[2002000];
int n,d;
inline int len(int l,int r){
	return abs(ls[r]-ls[l]);
}
inline bool isok(int l,int r){
	return len(l,r)<=d;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	while(t-->0){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>ls[i];
		}
		ls[0]=0;
		ls[n+1]=0;
		fill(ljmp,ljmp+n+10,0);
		fill(rjmp,rjmp+n+10,0);
		fill(v,v+n+10,0);
		for(int i=1;i<=n-3;i++){
			v[i]=(!isok(i,i+3))&&isok(i,i+2)&&isok(i+1,i+3);
		}
		for(int i=1,last=0;i<=n-3;i++){
			if(v[i]){
				ljmp[i]=last;
				rjmp[last]=i;
				last=i;
			}
		}
		rjmp[0]=0;
		int ret=0;
		for(int i=1;i<=n-3;i++){
			if(v[i]){
				if(ljmp[i])
				ret+=i-ljmp[i]-1;
				if(rjmp[i])
				ret+=rjmp[i]-i-1;
				ret++;
			}
		}
		cout<<ret<<'\n';
	}
}
