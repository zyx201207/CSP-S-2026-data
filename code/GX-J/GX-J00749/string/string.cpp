#include <bits/stdc++.h>
using namespace std;
int n,x[200],ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char y[200];
    int j=0,sum=0;
    char s[10000];
    for(int k=1;k<=n;k++){
        cin>>x[k]>>y[k];
        sum+=x[k];
        while(x[k]!=0){
            s[j]=y[k];
            j++;
            x[k]--;
        }
    }
    for(int i=1,j=sum;i<j;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
