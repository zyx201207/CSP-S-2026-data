#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,sum;
int a[N];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		sum=(a[i]&a[i+1]);
	}
	cout<<sum;
	return 0;
}

