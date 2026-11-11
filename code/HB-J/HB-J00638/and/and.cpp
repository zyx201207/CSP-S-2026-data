#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> sum;
string Hon(int n)
{
    string sum="";
    int m=1;
    while(true)
    {
        if(n>=2^m&&n<2^(m+1))
        {
            break;
        }
        m++;
    }
    while(true)
    {
        for(int i=m;i>=1;i--)
        {
            if(n>2^i)
            {
                n=n-(2^i);
                sum.push_back('1');
            }else{
            sum.push_back(0);
            }
        }
    }
    return sum;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int nsnngnn;
    string ido;
    for(int i=1;i<=n;i++)
    {
        cin>>nsnngnn;
        sum.push_back(nsnngnn);
        ido=Hon(sum[i]);
    }
    sort(sum.begin(),sum.end());
    cout<<sum[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
