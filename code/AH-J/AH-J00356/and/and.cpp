#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
sort(a+1,a+n+1,cmp);
if(m==1) cout<<a[1];
else cout<<"0";
	return 0;
} 
