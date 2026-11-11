#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+50;
bool cmp(int a,int b){
	return a>b;
}
int a[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
	}
	int ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
