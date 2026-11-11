#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int D=1e6+10;
int n,m,A[D],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A,A+n,greater<int>());
	for(int i=0;i<m-1;i++)
	{
		A[i]=A[i]&&A[i+1];
	} 
	ans=A[m];
	cout<<ans;
	return 0;
}
