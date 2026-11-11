#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    freopen(string.in,"w",std.in);
    freopen(string.out,"r",std.out);
    int n,s=0;
    cin >> n;
    long a[100005],q[100005];
    memset(q,0,sizeof(q));
    string c[100005],st;
    for(int i=1;i <= n;i++){
        cin >> a[i] >> c[i];
        q[i]+=a[i]+q[i-1];
    }
    int mid=q[n]/2,id=0;
    for(int i=1;i<=n;i++){
        id++;
        if(q[i]>=mid) break;
    }
    for(int i=1;i <= n;i++)
    {
        for(int j=1;j <= a[i];j++)
        {
            st=st+c[i];
        }
    }
    for(int i=0;i <= mid;i++){
        if(st[i]!=st[q[n]-i-1]) s++;
    }
    cout << s;
    return 0;
}
