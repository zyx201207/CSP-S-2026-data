#include<bits/stdc++.h>
using namespace std;
long long n,m[2000005],z1,z2;
char c[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i]>>c[i];
    }
    z1=1;
    z2=n;
    long long cnt=0;
    while(z2>z1)
    {
        if(c[z1]==c[z2]){
            if(m[z1]>m[z2]) {
                z1++;
                m[z2]-=m[z1];
            }
            else{
                z2--;
                m[z1]-=m[z2];
            }
        }
        else {
            if(m[z1]>m[z2])
            {
                m[z1]-=m[z2];
                cnt+=m[z2];
                z2--;
            }
            else {
                m[z2]-=m[z1];
                cnt+=m[z1];
                z1++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
