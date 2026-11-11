#include<bits/stdc++.h>
using namespace std;
struct p{
    long long s;
    char m;
};
p a[200005];
long long sum=0,n,cl=0,ans=0,dai=0,dai2=0;
char daim,daim2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s>>a[i].m;
        sum+=a[i].s;
    }
    int i=1,j=n;
    while(i<=j)
    {
        if(dai==0)
        {
            dai=a[i].s;
            daim=a[i].m;
            i++;
        }
        if(dai2==0)
        {
            dai2=a[j].s;
            daim2=a[j].m;
            j--;
        }
        //cout<<ans<<" "<<cl<<" "<<dai<<" "<<dai2<<endl;
        if(daim==daim2)
        {
            if(sum/2-cl<min(dai,dai2))
            {
                break;
            }
            cl+=min(dai,dai2);
            long long sk=dai;
            dai-=min(dai,dai2);
            dai2-=min(sk,dai2);
        }
        else
        {
            if(sum/2-cl<min(dai,dai2))
            {
                ans+=(sum/2-cl);
                break;
            }
            ans+=min(dai,dai2);
            cl+=min(dai,dai2);
            long long sk=dai;
            dai-=min(dai,dai2);
            dai2-=min(sk,dai2);
        }

    }
    cout<<ans;
    return 0;
}
