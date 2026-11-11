//GZ-J00427 兴义市弘毅中学 罗曾琦 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1100000],s[1100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=n;i++)
    {
    	if(i<=m)
    	{
    		cout<<1;
		}else{
			cout<<0;
		}
	}
    return 0;
}
