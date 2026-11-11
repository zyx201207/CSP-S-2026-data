#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+5;
long long a[N];
bool cmp(int b,int c){
	return b>c;
}
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long ans=a[0] ;
	for(int i=1;i<m;i++){
		ans=ans & a[i];
	}
	cout<<ans;
	return 0;
}
