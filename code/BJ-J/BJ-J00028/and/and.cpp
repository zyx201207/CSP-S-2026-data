#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5 + 1;

int n, m, a[MAXN], ans[31];

void turn(int x)
{
    for(int i =31;i >= 0;i--) cout<< bool(((1<<i) & x));
    cout<<endl;
    return;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);

    for(int i = 30 ;i >= 0;i--)
    {
        int sum = 0;
        for(int j = 1;j <= n;j++)
        {
            if(bool(a[j] & (1<<(i + 1))) == 0 && ans[i + 1] == 1) a[j] = 0;
            sum += bool(a[j] & (1<<i));
            //printf("i:%d j:%d",i,j);turn(a[j]);
        }


        if(sum < m) ans[i] = 0;
        else ans[i] = 1;

        //cout<<ans[i]<<" "<<sum<<endl;

    }

    int cnt = 0;
    for(int i = 31;i >= 0;i--) cnt += (ans[i] * (1<<i));

    cout<<cnt;

    return 0;
}
