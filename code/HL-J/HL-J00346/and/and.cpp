#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	
	return 0;
}
