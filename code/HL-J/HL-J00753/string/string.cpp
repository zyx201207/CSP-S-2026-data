#include<bits/stdc++.h>
using namespace std;
int nums[1000000000];
int main()
{
 	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    string str;
    for(int i=1;i<=n;i++)
    {
    	cin>>nums[i];
    	string s;cin>>s;
    	str[i]+=s;
	}
	cout<<str;
 	return 0;
}