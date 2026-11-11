#include<bits/stdc++.h>
using namespace std;
char a[100005];
int t[150];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        string s;
        for(int j=i;j<=n;j++){
            if(s.find(a[j],0)==-1){
                s+=a[j];
            }else{
                s.erase(s.find(a[j],0),(s.size()-s.find(a[j],0)+1));
                s+=a[j];
            }
        }
        for(int j=0;j<s.size();j++){
            t[s[j]-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
