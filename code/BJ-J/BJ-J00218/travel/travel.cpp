#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char ans[4],in[2][4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,now=1;
    string s[2];
    cin>>c1>>s[1]>>c2>>s[2];
    for(int i=1;i<=2;i++){
        for(int j=1;j<=3;j++);{
            in[i][j]==s[i].now;
            now++;
            if(now==4)    now=1;
        }
    }
    if(c1==c2){
        ans[1]='1';
    }
    else{
        cout<<ans;
        return 0;
    }
    if(in[1][1]==in[2][1]){
        break;
    }
    else{
        cout<<ans;
        return 0;
    }
    if(in[1][2]==in[2][2]){
        ans[2]=='1';
        break;
    }
    else{
        cout<<ans;
        return 0;
    }
    if(in[1][3]=='A'||in[1][3]=='B'||in[1][3]=='C'){
        if(in[2][3]=='A'||in[2][3]=='B'||in[2][3]=='C'){
            ans[3]=1;
            if(in[1][3]=='A'&&in[2][3]=='B'){
                ans[4]=1;
                cout<<ans;
            }
            else if(in[1][3]=='B'){
                ans[4]=1;
                cout<<ans;
            }
            if(in[1][3]=='C'&&in[2][3]=='B'){
                ans[4]=1;
                cout<<ans;
            }
            else{
                cout<<ans;
                return 0;
            }
        }
        else{
            cout<<ans;
            return 0;
        }
    }
    else{
        if(in[2][3]=='D'||in[2][3]=='F'){
            ans[3]=1;
            ans[4]=1;
            cout<<ans;
            return 0;
        }
        else{
            cout<<ans;
            return 0;
        }
    }
    return 0;
}