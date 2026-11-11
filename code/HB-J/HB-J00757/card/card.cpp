#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],c[300005];
    memset(c,0,sizeof(c));
    string s="";
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            string b="";
            s+=a[i];
            for(int j=0;j<s.size();j++){
                if(s[j]==(char)a[i]){
                    b+=a[i];
                    s=b;
                    break;
                }
                b+=s[j];
            }
        }
        for(int j=1;j<=m;j++){
            for(int p=0;p<s.size();p++){
                if(s[p]==(char)j){
                    c[j]++;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
