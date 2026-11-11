#include<bits/stdc++.h>
using namespace std;
string c;
char s[2000000005],a[2000000005];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i,j=0,t=0;
    cin>>n;
    while(n--)
    {
        cin>>i>>c;
        while(i--)
        {
            s[j]=c[0];
            j++;
        }
	}
    i=0;j--;

     while(i<j)
        {
            if(s[i]!=s[j])
            {
                t++;
            }
            i++;j--;
        }

    cout<<t;
    return 0;
}
