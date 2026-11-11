#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans=0;
int a[200100];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int num=0,ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
		num++;
		if(num==m){
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*

*/ 
