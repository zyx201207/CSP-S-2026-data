#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string str;
    int cnt=0;
    for(int i=0;i<=n-1;i++)
    {
        int a;
        string s;
        cin>>a>>s;
        for(int j=1;j<=a;j++)
        {
            str+=s;
        }
    }
    for(int i=0;i<=(str.size()-1)/2;i++)
    {
    	if(str[i]!=str[str.size()-1-i])
        {
            cnt+=1;
        }
	}
	cout<<cnt;
    return 0;
}
