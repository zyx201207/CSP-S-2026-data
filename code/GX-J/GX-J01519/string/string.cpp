#include<iostream>
#include<map>
#include<math.h>
typedef long long ll;
using namespace std;

ll n;
char ipc[200005];
ll letter[256];
ll tmp;
ll ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>letter[i]>>ipc[i];
    }

    int mid;
    if(n%2==0) mid=n/2;
    else mid=n/2+1;

    for(int i=1,j=n;i<=mid && j>=mid;i++,j--)
    {
        if(ipc[i]!=ipc[j] && letter[i]>letter[j])
        {
            ipc[j]=ipc[i];
            tmp=letter[i]-letter[j]+tmp;
            ans+=max(letter[i],letter[j]);
        }
        else if(ipc[i]!=ipc[j] && letter[i]<letter[j])
        {

            ipc[i]=ipc[j];
            tmp=letter[j]-letter[i]+tmp;
            ans+=max(letter[i],letter[j]);
        }
        else if(ipc[i]!=ipc[j] && letter[i]==letter[j])
        {
            ipc[j]=ipc[i];
            ans+=letter[i];
            tmp=0;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
