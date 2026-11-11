//GZ-J00488 方沛琪
#include <iostream>
using namespace std;
int n,cnt=0,cnta=0;
char all[1000000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        for(int i=1;i<=a;i++)
        {
            all[cnta+i]=b;
        }
        cnta+=a;
    }
    for(int i=1;i<=cnta/2;i++)
    {
        if(all[i]!=all[cnta+1-i])
        {
            cnt+=1;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
