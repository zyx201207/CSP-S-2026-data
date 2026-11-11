#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef unsigned long long ll;
ll n,m,ans;
ll a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 
