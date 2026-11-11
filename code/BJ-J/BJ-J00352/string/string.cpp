#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node
{
    long long tim;
    char c;
    void read()
    {
        cin>>tim>>c;
    }
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i].read();
    }
    int l=1,r=n;
    long long left=a[1].tim,right=a[n].tim;
    long long ans=0;
    while(l<=r)
    {
		//cout<<l<<" "<<r<<" "<<left<<" "<<right<<" "<<ans<<endl;
        if(a[l].c!=a[r].c)
        {
            if(left>right)
            {
                ans+=right;
                left-=right;
                right=a[--r].tim;
            }
            else
            {
                ans+=left;
                right-=left;
                left=a[++l].tim;
            }
            if(left==0)l++,left=a[l].tim;
            if(right==0)r--,right=a[r].tim;
        }
        else
        {
			if(left>right)
			{
				left-=right;
				r--;
				right=a[r].tim;
			}
			else
            {
                right-=left;
                l++;
                left=a[l].tim;
            }
            if(left==0)l++,left=a[l].tim;
            if(right==0)r--,right=a[r].tim;
		}
    }
    cout<<ans<<endl;
    return 0;
}
