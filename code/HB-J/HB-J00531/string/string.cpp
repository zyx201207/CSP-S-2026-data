#include <bits/stdc++.h>
using namespace std;
long long a[200005],ans;
int n;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int j=n,i=1;
    while(i<=j){
        if(c[i]!=c[j]){
            if(a[i]<a[j])
            {
                a[j]-=a[i];
                ans+=a[i];
                i++;
            }
            else if(a[i]>a[j]){
                a[i]-=a[j];
                ans+=a[j];
                j--;
            }
            else{
                ans+=a[i];
                i++;
                j--;
            }
        }
        else{
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
