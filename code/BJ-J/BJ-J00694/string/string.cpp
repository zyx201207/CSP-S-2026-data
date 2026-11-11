#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int cnt=0,i=1,j=n;
    while(true){
        if(i==j)break;
        if(a[i]>=a[j]){
            if(c[i]!=c[j]){
                cnt+=a[j];
            }
            a[i]-=a[j];
            j--;
        }
        else{
            if(c[i]!=c[j]){
                cnt+=a[i];
            }
            a[j]-=a[i];
            i++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
