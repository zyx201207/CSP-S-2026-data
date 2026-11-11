#include<iostream>;
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int head=0;
    int tail=0;
    int f=0;
    int n=0;
    int ans=0;
    int a[100000]={0};
    string c[100000];
    string d[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<a[i];i++)
       {
          d[f]=c[i];
          f++
       }

    }
    while(head<=tail)
    {
        if(d[head]!=d[tail])
        {
            ans++
        }
    }
    cout<<ans;
}
