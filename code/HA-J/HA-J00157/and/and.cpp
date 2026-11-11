#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int sear(int sum,int x,int j){
	if(x==m)return sum;
	int suma=sum;
	for(int i=j;i<n-m+x;i++){
		suma=max(suma,sear(a[i]&sum,x+1,i+1));
	}
	return suma;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=0;i<n-m;i++){
		ans=max(ans,sear(a[i],1,i+1));
	}
	cout<<ans<<"\n";
	return 0;
}
