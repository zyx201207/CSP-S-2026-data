#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5; 
int n,m;
int a[N];
int v[N],Top=0;
bool f[N];
void clr(int d);
int slv(int d);
void cwv(int d);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){ 
		cin>>a[i];
		cwv(a[i]);
	}
//	cout<<"ck1\n";
	
	if(n<=30){//(0,30]ac 5/20 25
		int ans=-1;
		for(int i=1;i<(1<<n);++i)
			ans=max(ans,slv(i));
		cout<<ans;
	}
	else {
		int ans=0;
		for(int i=Top;i>=0;--i){//30
//			cout<<"ck2\n";
			if(v[i]>=m){
//				cout<<"ck3\n";
				ans+=(1<<i);
				clr(i);
			}
		}
//	cout<<"ck4\n";
		cout<<ans; 
	}
	
	
 return 0;
}
void clr(int d){
	for(int i=1;i<=n;++i){//n
		if(f[a[i]]||(a[i]/(1<<d)&1))continue;
		int x=a[i],t=0;
		while(x){//30
			if(x&1)--v[t];
			++t,x>>=1;
		}
		f[a[i]]=true;
	}
}
void cwv(int d){
	int i=0;
	while(d){
		if(d&1){
			++v[i];
			Top=max(Top,i);
		}
		++i,d>>=1;
	}
	return;
}
int slv(int d){//30ac
	int i=1,w=0,ans=(1<<30)-1;
	while(d){
		if(d&1){
			++w;
			ans&=a[i];
		}
		if(w>m)return -1;
		++i,d>>=1;
	}
	return (w==m?ans:-1); 
}
