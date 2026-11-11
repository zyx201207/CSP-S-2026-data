#include<bits/stdc++.h>
using namespace std;
int n,c=0;

struct p{
    int x;
    char y;
}a[200000];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        s.append(a[i].y,a[i].x);
    }
    int len=s.size();
    for(int i=0;i<=len-1;i++){
        if(s[i]!=s[len-i]){
            c++;
        }
    }
    if(c==0){
        cout<<0;
    }
    else{
        cout<<c;
    }

    return 0;
}
