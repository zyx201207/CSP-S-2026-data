#include<bits/stdc++.h>
using namespace std;
long long cnt;
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i,j,a;
    char c;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a>>c;
        for(j=0;j<a;j++){
            str+=c;
        }
    }
    for(i=0;i<(int)(str.size())/2;i++){
        cnt+=(str[i]!=str[str.size()-i-1]);
    }
    cout<<cnt;
    return 0;
}
