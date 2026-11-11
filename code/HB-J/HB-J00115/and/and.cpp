#include <bits/stdc++.h>
using namespace std;
void test(int b,int n,int m,long long num[200005],long long sum[2^30][200005],int cnt)
{
    cnt++;
    if(cnt<=m)
    {
        for(int i=b;i<n;i++)
        {
            sum[cnt-1][i] = num[i];
            test(i+1,n,m,num,sum,cnt);
        }
    }
}
bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long num[200005], sum[2^30][200005];
    cin >> n,m;
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
    }
    test(0,n,m,num,sum,0);
    int sum0[n/2*(n-1)+1];
    for(int i=0;i<n/2*(n-1);i++)
    {
        sum0[i]=sum[i][0];
        for(int j=0;j<m;j++)
        {
            sum0[i] = sum0[i] & sum[i][j];
        }
    }
    sort(sum0,sum0+n/2*(n-1),cmp);
    cout << sum0[0];

    return 0;
}
