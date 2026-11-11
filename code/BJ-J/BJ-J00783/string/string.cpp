#include<bits/stdc++.h>
using namespace std;
int n,a[20005],c[2000005],ans=0;
long long s=0;
char b[20005],S[205];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    c[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];
        s=s+a[i];
    }
    int d=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<a[i];j++){
            S[d]=b[i];
            d++;
        }
    }

   // cout<<S;
    for(int i=0;i<(s+1)/2;i++){
        char h=S[i],H=S[s-i-1];
        //cout<<h<<" "<<H<<endl;
        if(h!=H) ans++;
    }
    cout<<ans;
return 0;
}
