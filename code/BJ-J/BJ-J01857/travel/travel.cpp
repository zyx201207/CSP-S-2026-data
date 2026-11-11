#include <bits/stdc++.h>
using namespace std;
int n,m;//车厢
int x,y;//排数
char a,b;
char ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>x>>a;
    cin>>m>>y>>b;
    if(n==m){
        ans[0]='1';
    }
    else{
        ans[0]='0';
    }
    if(x==y&&ans[0]=='1'){
        ans[1]='1';
    }
    else{
        ans[1]='0';
    }
    if(ans[1]=='1'){
        if(a>='A'&&a<='C'){
            if(b>='A'&&b<='C'){
                ans[2]='1';
            }
            else{
                ans[2]='0';
            }
        }
    }
    else{
        if(b=='D'||b=='F'){
            ans[2]='1';
        }
        else{
            ans[2]='0';
        }
    }
    if(ans[2]=='1'){
        if(a=='D'||a=='F'){
            ans[3]='1';
        }
        else if((a=='A'&&b=='B')||(a=='C'&&b=='B')||(a=='B'&&b=='C')||(a=='B'&&b=='A')){
            ans[3]='1';
        }
        else{
            ans[3]='0';
        }
    }
    else{
        ans[3]='0';
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
