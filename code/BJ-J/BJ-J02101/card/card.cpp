#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[300010];
int ans[500010];
int ab[500010];
string s;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            s.insert(s.size(),a[i]+'0',1);
            b[a[i]]=s.size()-1;
        for(int j=i+1;j<=n;j++){
            if(b[a[j]]!=0){
                s.erase(b[a[j]]+1);
                continue;
            }
            s.insert(s.size(),a[j]+'0',1);
            b[a[j]]=s.size()-1;
        }
        for(int j=0;j<s.size(),j++){
            ab[s[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(ab[j])ans[j]++;
            ab[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
