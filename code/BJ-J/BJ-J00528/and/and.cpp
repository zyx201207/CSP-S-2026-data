#include <bits/stdc++.h>
using namespace std;
int n,m;
const long long pre=1073741823;
long long a[200005],ans=-1;

void olivia(int r,int w,int num) //r轮数 w从哪下标开始 num现在的值
{
    if(r<=0||w>=n)
    {
        ans= max(ans,(long long)num);
        //cout << "max"<<ans<<endl;
        return;
    }
    for(int i=w;i<n+1-r;i++)
    {
        //cout << num<<"and" << a[i]<<"="<<(num & a[i])<<endl;
        olivia(r-1,i+1,(num & a[i]));
    }
    return;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    olivia(m,0,pre);
    cout <<ans;
    fclose(stdin);
    fclose(stdout);
}
