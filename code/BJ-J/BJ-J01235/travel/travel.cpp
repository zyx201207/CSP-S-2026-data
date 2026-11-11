#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s1,s2,c1,c2,ans;
    cin >> c1 >> s1 >> c2 >> s2;
    a=s1[2]+'0';
    b=s2[2]+'0';
    if(c1==c2){
        cout << 1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout << 1;
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
                cout << 1;
                if(a-b==1||b-a==1)cout << 1;
                else cout << 0;
            } else cout << 0 << 0;
        }else cout << 0 << 0 << 0;
    } else cout << 0 << 0 << 0 << 0;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

