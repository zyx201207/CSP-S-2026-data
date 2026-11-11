#include <bits/stdc++.h>
using namespace std;
int n,m;
string a[1000000];
int b[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        string s;
        for(int j=i;j<=n;j++){
            if(s.find(a[j])>=0){
                if(s.find(a[j])==0)
                    s.erase(0,s.size());
                else{
                    s=s.substr(0,s.find(a[j])-1);
                }
            }
            s+=a[j];
        }
        for(int k=0;k<s.size();k++){
            int t=s[k]-'0';
            b[t]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
