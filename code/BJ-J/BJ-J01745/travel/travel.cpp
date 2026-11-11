#include <bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
bool check(int a,int b){
    if (a-65<=2 && b-65<=2){
        return true;
    }
    else if (a-65>2 && b-65>2){
        return true;
    }
    return false;
}
bool check2 (int x,int y){
    if (x-y==1 || y-x==1){
        if (x>y && x!='D'){
            return true;
        }
        else if (y>x && y!='D'){
            return true;
        }
    }
    return false;

}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2 && c1!="01" && c1!="16"){
        cout<<1;
        if (s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if (check(s1[2],s2[2])){
                cout<<1;
                if (check2(s1[2],s2[2])){
                    cout<<1;
                }
                else {
                    cout<<0;
                }
            }
            else {
                cout<<0<<0;
            }
        }
        else {
            cout<<0<<0<<0;
        }


    }
    else {
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
