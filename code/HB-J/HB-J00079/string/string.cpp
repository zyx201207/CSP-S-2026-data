#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    ll num;
    char c;
}chars[200500];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>chars[i].num;
        cin>>chars[i].c;
    }
    ll rest_chars_size=n;
    ll leftz=0;
    ll rightz=n-1;
    while(rest_chars_size>1){
        Node firstone=chars[leftz];
        Node lastone=chars[rightz];
        if(firstone.c==lastone.c){
            if(firstone.num>lastone.num){
                chars[leftz].num-=(lastone.num);
                rightz-=1;
            }
            if(lastone.num>firstone.num){
                chars[rightz].num-=(firstone.num);
                leftz+=1;
            }
            if(firstone.num==lastone.num){
                rest_chars_size--;
                leftz++;
                rightz--;
            }
        }
        else{
            if(firstone.num>lastone.num){
                chars[leftz].num-=(lastone.num);
                ans+=lastone.num;
                rightz-=1;
            }
            if(lastone.num>firstone.num){
                chars[rightz].num-=(firstone.num);
                ans+=firstone.num;
                leftz+=1;
            }
            if(firstone.num==lastone.num){
                rest_chars_size--;
                leftz++;
                rightz--;
                ans+=firstone.num;
            }
        }
        rest_chars_size--;
    }
    cout<<ans;
    return 0;
}

/*

        if(firstone.num>lastone.num){
            chars[leftz].num-=(lastone.num);
            ans+=lastone.num;
            rightz-=1;
        }
        if(lastone.num>firstone.num){
            chars[rightz].num-=(firstone.num);
            ans+=firstone.num;
            leftz+=1;
        }

*/
