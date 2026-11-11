#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int ans;
char a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>a;
        for(int j=1;j<=m;j++){
            s+=a;
        }
    }
    int j=s.size()-1;
    for(int i=0;i<j;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
