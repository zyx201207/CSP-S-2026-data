#include<bits/stdc++.h>
using namespace std;
const long long maxn=200000;
struct gy
{
    char b;
    unsigned long long a;
};
gy op[maxn+5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>op[i].a>>op[i].b;
    int r=1,l=n;
    long long ans=0;
    while(l!=r)
    {
        if(op[l].b==op[r].b)
        {
            if(op[l].a==op[r].a)
            {
                l--;
                r++;
            }
            else if(op[l].a<op[r].a)
            {
                op[r].a-=op[l].a;l--;
            }
            else{
                op[l].a-=op[r].a;r++;
            }
        }
        else{
            if(op[l].a==op[r].a)
            {
                ans+=op[l].a;
                l--;
                r++;
            }
            else if(op[l].a<op[r].a)
            {
                ans+=op[l].a;
                op[r].a-=op[l].a;l--;
            }
            else if(op[l].a>op[r].a){
                ans+=op[r].a;
                op[l].a-=op[r].a;r++;
            }
        }
    }
    cout<<ans;
}