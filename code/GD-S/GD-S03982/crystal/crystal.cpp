//crystal.cpp  AC
#include<bits/stdc++.h>
#define MAXN 1000005 //1e6
using namespace std;
using ull = unsigned long long ;
using ll = long long;
ll a[MAXN];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	//0th
	ull n,m;
	cin>>n>>m;
	//m = m<<30;
	for(ll i = 0;i<n;i++){
		scanf("%lld",&a[i]);
		//a[i] = a[i]<<30;//db
	}
	sort(a,a+n);//ÉýÐò 
	
	//1st
	ull g_1 = 0;//i=0
	ull s = 0;
	
	ull g = 0;
	ull ans = 0;
	for(ll i = 1;i<n;i++){
		g = g_1 + (ull)((a[i]-a[i-1])*(i-s)) ;
		if(g>m){//×·Çó<=m 
			while(g>m)g -= (ull)(a[i]-a[s++]);
		}
		ans = max(ans,i-s+1);
		g_1 = g;//¼Ì³Ð 
	}
	
	cout<<ans;
}
