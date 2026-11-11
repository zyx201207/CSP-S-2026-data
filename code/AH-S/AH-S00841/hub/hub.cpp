#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,INF=0x3f3f3f3f;
int n,k,ccc;
int pd[N];
vector<int> l[N];
void B(int bh,int st){
	ccc++;
	if(st==0) return;
	for(auto v:l[bh]){
		if(!pd[v]){
			pd[v]=true;
			B(v,st-1);
			pd[v]=false;
		}
	}
}
bool check(int x){
	int fi=0,se=0;
	for(int i=1;i<=n;i++){
		ccc=0;
		B(i,x);
		if(ccc>=fi) se=fi,fi=ccc;
		else if(ccc>=se) se=ccc;
		if(fi+se>=k) return true;
	}
	if(fi+se>=k) return true;
	else return false;
}
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	int T2;
	T2=read();
	T=read();
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			l[u].push_back(v);
			l[v].push_back(u);
		}
		int l=1,r=n-1;
		while(l<r){
			int mid=(l+r)/2;
			if(!check(mid)) l=mid+1;
			else r=mid;
		}
		cout<<r<<endl;
	}
	
	return 0;
}
