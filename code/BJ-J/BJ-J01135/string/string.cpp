#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;

int n;
string ss;
char cc[200010];
long long leth=0,ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char s;
        cin>>a>>s;
        long long ll=leth+a;
        for(int j=leth;j<=ll;j++){
            cc[j]=s;
        }
        leth=ll;
    }
    for(int i=0;i<(leth/2);i++){
        if(cc[i]!=cc[leth-i-1]){
            ans++;
 //           cout<<cc[i]<<" "<<cc[leth-i]<<endl;
        }
    }
    cout<<ans;
    return 0;
}
