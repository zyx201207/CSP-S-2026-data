#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    int n,a,j,ans=0;
    char c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        while(a--)
        {
            s+=c;
        }
    }
    for(int i=0;i<floor(s.size()/2.0);i++)
    {
        j=s.size()-1;
        if(s[i]!=s[j])ans++;
        j--;
    }
    cout<<ans;
    return 0;
}
