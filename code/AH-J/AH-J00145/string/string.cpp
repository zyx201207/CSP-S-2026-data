#include<bits/stdc++.h>
using namespace std;
long long a1,n,xb=1,ans;
char b1;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a1>>b1;
        for(long long j=0;j<a1;j++){
            a[j+xb]=b1;
        }
        xb+=a1;
    }
    xb--;
    for(int i=1;i<=xb/2;i++){
        if(a[i]!=a[xb-i+1])
           ans++;
    }    
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
