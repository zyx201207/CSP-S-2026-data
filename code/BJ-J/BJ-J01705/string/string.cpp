#include<bits/stdc++.h>
using namespace std;
string s;
string s1[10001000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,l=0,cnt=0,s1cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char x1;
        cin>>x>>x1;
        for(int j=1;j<=x;j++){
            l++;
            s[l]=x1;
        }
        s1[i]=s;
    }
    int c=1;
    int cst=1;
    for(int i=0;i<l;i++){
        if(s[cst]!=s[l+1-cst]){
            c=0;
            cnt++;
        }
    }
    if(c==1){
        cout<<0;
    }
    else cout<<cnt/2;
    return 0;
}

