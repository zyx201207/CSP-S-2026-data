#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[200005],res;
void DFS(ll c,ll s,ll biao){
	if(c>m){
		res=max(res,s);
		return;
	}
	for(int i=biao+1;i<=n;i++){
		if(c==1){
			DFS(c+1,a[i],i);
		}else{
			ll s1=s&a[i];
			DFS(c+1,s1,i);
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20 && m!=1){//²âÊÔµã1~5 
		DFS(1,1,0);
		cout<<res;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];//²âÊÔµã6 
	}else{
		cout<<a[n-m+1];//²âÊÔµã13 
	}
// A:5 2
//   63 15 7 1 31
}
