#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        sum+=a[i];
    }
    if(sum%2==1){
        long long p=sum/2+1;
        for(int i=1;i<=n;i++){
            p-=a[i];
            if(p<=0){
                a[i]--;
                sum=i;
                break;
            }
        }
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    int p=0;
    for(int i=1;i<=n;i++){
        if(s[i]!=s[n-i+1]){
            p++;
        }
    }
    cout<<p;
    return 0;
}
