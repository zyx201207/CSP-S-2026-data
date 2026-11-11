#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
#define ll long long
ll n,m;
int main(){
	freopen("and.in","r".stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll a[100005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[2];
	return 0;
} 
