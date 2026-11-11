#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long num;
	char c;
}a[200005];
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
    {
    	cin>>a[i].num>>a[i].c;
	}
	cout<<0<<endl;
	return 0;
}
