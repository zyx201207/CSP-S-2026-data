#include<bits/stdc++.h>
using namespace std;
string s[100005],num;
int n,cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if((s[i]<='a')&&(s[i]>='z')){
            num+=s[i];
            cnt++;
        }
    }
    sort(s[0]+1,s[0]+num+1,rmp);
    for(int i=1;i<=cnt;i++){
        if(s[0]==s[0]+num){
            return 0;
        }
    }
    return 0;
}
