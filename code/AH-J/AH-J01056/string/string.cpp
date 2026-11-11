#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
char ss;
string q;
long long cnt;
string a=" ";
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s>>ss;
        cnt+=s;
        for(long long j=1;j<=s;j++){
            a+=ss;
        }
    }
    for(long long i=1;i<=cnt/2;i++){
        q[i]=a[i];
    }
    for(long long i=(cnt+1)/2+1;i<=cnt;i++){
        if(a[i]!=q[cnt-i+1]){
            ans++;
        }
    }

    cout<<ans;
    return 0;
}
