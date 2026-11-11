#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],pre[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=n-1;i>=1;i--){
		if(m>=pre[i]){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
