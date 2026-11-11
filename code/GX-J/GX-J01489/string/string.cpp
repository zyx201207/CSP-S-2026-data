#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,nu=0,m;
    char b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s=s+b;
        }
    }
    int k=s.size();
    if(k%2==0){
        k=k/2;
        k=k-1;
        m=s.size();
        m=m-1;
        for(int i=0;i<=k;i++){
            if(s[i]!=s[m-i]){
                nu++;
            }
        }
        cout<<nu;
        return 0;
    }else{
        k=k/2;
        m=s.size();
        m=m-1;
        for(int i=0;i<=k;i++){
            if(s[i]!=s[m-i]){
                nu++;
            }
        }
        cout<<nu;
        return 0;
    }
    return 0;
}
