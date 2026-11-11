#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s="";
ll n,a,cnt,l;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        l+=a;
        //朴素方法，待会对拍
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }for(int i=0,j=l-1;i<=j;i++,j--){
        if(s[i]!=s[j]) cnt++;
    }cout<<cnt;
    return 0;
}
//13～16，22～25拿不了，只能过最多17个点,68.
//对拍的对照组不会写qwq
