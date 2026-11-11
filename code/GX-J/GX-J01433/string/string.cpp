#include<bits/stdc++.h>
using namespace std;
int t,n,ans,nn[200005];
char aa[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>nn[i]>>aa[i];
        for(int j=n;j<n+nn[i];j++){
            s[j]=aa[i];
            
        }
        n=n+nn[i];
    }
    int k=n-1;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[k]){
            ans++;
        }
        k=n-1;

    }
    cout<<ans<<endl;
    return 0;
}
