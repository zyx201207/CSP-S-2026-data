#include<bits/stdc++.h> 
using namespace std;
#define ll long long
const int N=5e5+5;
int a[N],d[N];
int n;
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i] = a[i]+d[i-1];	
	}
	for(int i=n;i>=1;i--){
		if((d[i]+m)%i==0&&(d[i]+m)/i>=a[i]){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0; 
}//zzhIloveyou 
