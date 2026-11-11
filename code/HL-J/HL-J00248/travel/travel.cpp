#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans = "0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    //a:chexiang  b:pai  c:chexiang2 d:pai
    int a = (c1[0]-'0')*10+(c1[1]-'0');
    int b = (s1[0]-'0')*10+(s1[1]-'0');
    int c = (c2[0]-'0')*10+(c2[1]-'0');
    int d = (s2[0]-'0')*10+(s2[1]-'0');
    //first
    if(a==c){
        ans[0]='1';
    }else{
        cout << ans;
        return 0;
    }
    //second
    if(b==d){
        ans[1]='1';
    }else{
        cout << ans;
        return 0;
    }
    //third
    if(s1[2]=='D'){
        if(s2[2]=='F'){
            ans[2]='1';
        }else{
            cout << ans;
            return 0;
        }
    }else if(s2[2]=='D'){
        if(s1[2]=='F'){
            ans[2]='1';
        }else{
            cout << ans;
            return 0;
        }
    }else if(s1[2]!='D' && s2[2]!='F'){
        if(s1[2]!='F' && s2[2]!='D'){
            ans[2]='1';
        }else{
            cout << ans;
            return 0;
        }
    }else{
        cout << ans ;
        return 0;
    }
    //forth
    if(s1[2]=='D' || s1[2]=='F'){
        ans[3] = '1';
    }else if(s1[2]=='A' && s2[2]=='C'){
        cout << ans;
        return 0;
    }else if(s1[2]=='C' && s2[2]=='A'){
        cout << ans;
        return 0;
    }
    ans[3]='1';
    cout << ans;
    return 0;
}
