#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int cnt=0;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=m;i<=n;i++){
		int sum=a[i];
		for(int j=i+1;j<=m;j++){
			sum&=a[i-j];
		}
		cnt=max(cnt,sum);
	}
	cout<<cnt;
	return 0;
}
