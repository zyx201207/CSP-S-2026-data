#include <iostream>
using namespace std;
int n;
long long ans;
struct node
{
    int num;
    char ch;
}s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %c",&s[i].num,&s[i].ch);
    }
    if (n==1)
    {
        cout << 0;
        return 0;
    }
    int i=1,j=n;
    while (i<j)
    {
        if (s[j].ch!=s[i].ch)
            ans+=min(s[j].num,s[i].num);
        if (s[i].num>=s[j].num)
        {
            s[i].num-=s[j].num;
            j--;
            if (s[i].num==0)
                i++;
        }
        else
        {
            s[j].num-=s[i].num;
            i++;
            if (s[j].num==0)
                j--;
        }
    }
    printf("%lld",ans);
}
