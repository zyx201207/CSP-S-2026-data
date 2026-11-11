#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,r;
char ch;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>ch;
		for(int j=1;j<=a[i];j++)
		{
			st=st+ch;
		}
	}
	r=st.size();
	st=' '+st;
	for(int i=1;i<=(r+1)/2;i++)
	{
		if(st[i]!=st[r-i+1])
		{
			ans++;
		}
	}
	cout<<ans;
	
	
	return 0;
}
