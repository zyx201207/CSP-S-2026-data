#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {

        cin>>a[i]>>c[i];
    }
    long long ans=0;
    int i=1,j=n;
    while(i<j)
    {
        if(c[i]==c[j])
        {
            if(a[i]<a[j])
            {


                a[j]-=a[i];
                i++;
                continue;
            }
            else if(a[j]<a[i])
            {

                a[i]-=a[j];
                j--;
                continue;
            }
            else if(a[i]==a[j])
            {

                i++;
                j--;

                continue;
            }
        }
        else{
            if(a[i]<a[j])
            {

                ans+=a[i];
                a[j]-=a[i];
                i++;

                continue;
            }
            else if(a[i]>a[j])
            {

                ans+=a[j];
                a[i]-=a[j];
                j--;

                continue;
            }
            else if(a[i]==a[j])
            {
                ans+=a[i];
                i++;
                j--;
                continue;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


