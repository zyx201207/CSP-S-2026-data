#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,m,a[N],ans,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("str.in","r",stdin);
//	freopen("dog.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<=n-m;i++)
	{
		s=a[i];
		for(int j=1;j<m;j++)
			s=(s&a[j+i]);
		ans=max(ans,s);
//		cout<<s<<endl;
	}cout<<ans;
	return 0;
} 
