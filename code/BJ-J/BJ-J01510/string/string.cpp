#include<bits/stdc++.h>
using namespace std;
int sum;
char h[100000001];
int main()
{
	freopen('string.in','r',stdin);
    freopen('string.out','w',stdout);
    int n;
    cin>>n;
    int j=1,a1=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        a1+=a;
        for(;j<=a1;j++)
        {

            h[j]=c;
        }

    }
    int k=0;
    for(int i=j-1;i>=1;i--)
    {
        k++;
        if(i<=k)
        {
            break;
        }
        if(h[i]!=h[k])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}


