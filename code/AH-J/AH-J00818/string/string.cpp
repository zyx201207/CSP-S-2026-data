#include<bits/stdc++.h>
using namespace std;
struct node
{
    char ch;
    int num;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long T,sum=0;
    cin>>T;
    for(int i=1;i<=T;i++)
        cin>>a[i].num>>a[i].ch;
    int l=1,r=T;
    while(l<r)
    {
        if(a[l].ch==a[r].ch)
        {
            if(a[l].num>=a[r].num){a[l].num-=a[r].num;r--;}
            else {a[r].num-=a[l].num;l++;}
        }
        else
        {
            sum+=min(a[l].num,a[r].num);
            if(a[l].num>=a[r].num){a[l].num-=a[r].num;r--;}
            else {a[r].num-=a[l].num;l++;}
        }
    }
    cout<<sum;
    return 0;
}
