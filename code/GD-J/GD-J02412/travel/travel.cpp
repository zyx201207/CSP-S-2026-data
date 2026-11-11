#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
int ans[5];
int check1(string x,string y){
    int a=x[2]-'A'+1,b=y[2]-'A'+1;
    if(a<=3 and b<=3 or a>3 and b>3) return 1;
    return 0;
}
int check2(string x,string y){
    int a=x[2]-'A'+1,b=y[2]-'A'+1;
    if(a==6) a--;
    if(b==6) b--;
    if(a-b==1 or b-a==1) return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    cin>>r1>>r2>>x1>>x2;
	freopen("travel.out","w",stdout);
    if(r1[0]==x1[0] and r1[1]==x1[1]){
        cout<<'1';
        if(r2[0]==x2[0] and r2[1]==x2[1]){
            cout<<'1';
            if(check1(r2,x2)){
                cout<<'1';
                if(check2(r2,x2)){
                    cout<<'1';
                }
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
