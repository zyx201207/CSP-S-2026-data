#include <bits/stdc++.h>
using namespace std;
long long b;
bool p=true;
char m;
string a;
long long sum=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>m;
        sum+=b;
        for(int j=0;j<=b;j++)
            a+=m;
    }
    if(sum%2!=0)
        for(int i=0;i<=a.length();i++){
            if(i==(sum-1)/2)
                break;
            if(a[i]!=a[sum-i]){
                a[sum-i]=a[i];
                ans++;
            }
        }
    else
        for(int i=0;i<=a.length();i++){
            if(i=sum/2)
                break;
            if(a[i]!=a[sum=i]){
                a[sum-1]=a[i];
                ans++;
        }
    }
    cout<<ans;
    return 0;
}