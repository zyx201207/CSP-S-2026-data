#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char b[200010];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int i=1,j=n;
    while(i<j){
        if(b[i]!=b[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>a[j]){
                a[i]-=a[j];
                b[j]=b[i];
                i--;
        }
        else if(a[j]>a[i]){
            a[j]-=a[i];
            b[i]=b[j];
            j++;
        }
        else if(a[j]==a[i]) b[i]=b[j];
        i++,j--;
    }
    cout<<ans;
    return 0;
}
