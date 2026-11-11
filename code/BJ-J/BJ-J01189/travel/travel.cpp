#include<bits/stdc++.h>
#define ll long long
#define MAX 1000010
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int x=s1[0]*10+s1[1];
    int y=s2[0]*10+s2[1];
    if(c1!=c2){
        cout<<"0000";
    }else{
        if(x!=y){
            cout<<"1000";
        }else{
            if((s1[2]<='C'&&s2[2]<='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                if(abs(s1[2]-s2[2])==1){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else{
                cout<<"1100";
            }
        }
    }
    return 0;
}
