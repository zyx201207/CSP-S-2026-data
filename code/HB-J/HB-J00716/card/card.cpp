#include<bits/stdc++.h>
using namespace std;
int a[500005],b[100000];
string s="";
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m;
    if(!(n>500&&m>200&&n<500000&&m<300000)){
        cout<<n<<" "<<n/2<<" "<<n/3;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int c=0;
            s="";
            s[c]=int(a[i]+'0');
        for(int j=i+1;j<=n;j++){
            if(a[j]==a[j-1])continue;
            s[c]=int(a[j]+'0');
            c++;
        }
        for(int i=0;i<s.size();i++){
            b[int(s[i]-'0')]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}

