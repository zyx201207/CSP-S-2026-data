#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010

inline void read(int &x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

void fileIO(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int n,a[MAXN];
char c[MAXN];
long long ans;
void solve(){
	int l=1,r=n,suml=a[1],sumr=a[n]; 
	while(l<r){
		int minn=min(suml,sumr);
		if(c[l]!=c[r])ans+=minn;
	    suml-=minn;sumr-=minn;
	    if(suml==0){++l;suml=a[l];}
	    if(sumr==0){--r;sumr=a[r];}
	}
}

int main(){
	fileIO("string");
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		cin>>c[i];
	}
	
	solve();
	cout<<ans;
	return 0;
}
