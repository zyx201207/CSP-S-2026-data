#include <bits/stdc++.h>
using namespace std;
string l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n,a,cnt=0;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        for(int j=1;j<=a;i++){
            l+=c;
        }
    }

    for(int i=1;i<=l.length();i++){
        int len=l.length();
        if(l[i]==l[len]){
            continue;
        }else{
            l[len]=l[i];
            cnt++;
        }
        len--;
        if(i==len){
            break;
        }
    }
    cout<<cnt;
    return 0;
}
