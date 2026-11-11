#include <bits/stdc++.h>

using namespace std;
const int MAX=1e6+5;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    unsigned long long sum=0,ans=0;
    int n;
    cin>>n;
    int i;
    int num;
    char t;
    char a[MAX];
    for(i=1;i<=n;i++)
    {
        cin>>num;
        cin>>t;
//        cout<<num<<" "<<t<<endl;
//    }
//    return 0;
//}
        while(num)
        {
            a[++sum]=t;
            num--;
        }
    }
    for(i=1;i<=sum/2;i++)
    {
        if(a[i]!=a[sum-i+1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
