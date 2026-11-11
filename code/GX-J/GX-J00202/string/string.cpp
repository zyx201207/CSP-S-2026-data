#include<bits/stdc++.h>
using namespace std;
string s;
char c[1001000];
int n;
long long a[1001000];
long long ans,cnt;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
        ans+=a[i];
    }
    //int j=1;
    //for(int i=1;i<=n/2;i++){
    //    while(a[i]-a[n-j+1] >= 0){
    //        if(c[i]!=c[n-j+1]){
    //            cnt+=a[n-j-1];
    //            a[i]-=a[n-j+1];
    //        }
    //        j++;
    //   }
    //    if(a[i]>=0){
    //        cnt+=a[i];
     //   }

    //}
    for(int i=0;i<ans/2;i++){
        if(s[i]!=s[ans-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

