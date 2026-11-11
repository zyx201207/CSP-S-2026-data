#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],s[N],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++)
		s[i]=s[i-1]&a[i];
	for(int i=1;i<m;i++)
		s[i]=0;
	for(int l=1;l<=n;l++){
		int r=l+m-1;
		if(r>n)
			break;
		int add=s[r]|s[l-1];
		ans=max(ans,add);
	}
	cout<<ans;
	return 0;
}
