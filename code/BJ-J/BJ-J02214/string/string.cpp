#include<bits/stdc++.h>
using namespace std;
int n,ai;
char ch;
string st;
int len[1000001];
//int c=1e4;
int main(){
    //:
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //
    cin>>n;
    int co=0;
    unsigned long long ans=0;
    unsigned long long lens=0;
    for(int i=1;i<=n;i++){
        cin>>ai>>ch;
        if(ai>=10000){
            co=1;
        }
        if(co==0){
            lens+=ai;
            for(int j=1;j<=ai;j++){
                st+=ch;
            }
        }
        lens+=ai;
        len[i]=ai;
    }
    if(co==0){
        for(int k=0;k<st.size()/2;k++){
            if(st[st.size()-k-1]==st[k]){
            }else{
                st[st.size()-k-1]=st[k];
//                cout<<st[lens+1-k]<<" "<<st[k];
                ans++;
            }
        }
    }
    if(co==1){
    unsigned long long t=lens/2,u=0;
        for(int i=1;i<=n;i++){
            u+=len[i];
            if(u>=t){
                break;
           }
        }
        ans=lens-u;
    }
    cout<<ans;
return 0;
}