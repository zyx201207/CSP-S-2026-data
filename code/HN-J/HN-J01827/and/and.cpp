#include <bits/stdc++.h>
using namespace std;
/*int btoi(int x,int y){
	vector<bool> a,b;
	while(x){
		if(x&1) a.push_back(true);
		else a.push_back(false);
		x>>=1;
	}
	while(y){
		if(y&1) b.push_back(true);
		else b.push_back(false);
		y>>=1;
	}
	int ans=0,bt=1,i;
	int mn=min(a.size(),b.size());
	for(i=0;i<mn;i++){
		if(a[i]&&b[i]) ans+=bt;
		bt<<=1;
	}
	return ans;
}*/
int btoi(vector<int> a){
	int ans=0;int bt=1;
	while(true){
		bool f=true;
		for(int i=0;i<a.size();i++){
			if(!(a[i]&1)){
				f=false;
			} 
		}
		if(f) ans+=bt;
		bt<<=1;
		for(int i=0;i<a.size();i++){
			a[i]>>=1;
		}
		bool g=true;
		for(int i=0;i<a.size();i++){
			if(a[i]) g=false;
		}
		if(g) break;
	}
	return ans;
} 
void mx(const vector<int>& a,vector<int>& cr,const int& st,const int& re,long long& ma,const int& n){
	if(re==0){
		long long ans=ans=btoi(cr);
		ma=max(ma,ans);
		return;
	}
	for(int i=st;i<=n-re;i++){
		cr.push_back(a[i]);
		mx(a,cr,st+i,re-1,ma,n);
		cr.pop_back();
	}
	return;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ma=0;
	vector<int> cr;
	mx(a,cr,1,m,ma,n);
	printf("%lld\n",ma);
	return 0;
}
