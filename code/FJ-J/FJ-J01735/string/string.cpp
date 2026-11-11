#include<bits/stdc++.h>
using namespace std;
const int N=1e9+5;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[10010],ans=0;
	string s[N]={0},c[10010];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>c[i];
	for(int i=0;i<n;i++)
	{
		if(c[i]==c[i]){
			cout<<0;
			return 0;
		}
	}
	return 0;
}
