///今年的j1分数线低一点吧！！！！！！！！
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    else {
        if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
            cout<<"1000\n";
            return 0;
        }
        else {
            char ss1=s1[2],ss2=s2[2];
            if(!((ss1>='A'&&ss1<='C'&&ss2>='A'&&ss2<='C')||((ss1=='D'&&ss2=='F')||(ss2=='D'&&ss1=='F')))){
                cout<<"1100\n";
                return 0;
            }
            else {
                if(!((ss1+1==ss2||ss1-1==ss2)||((ss1=='D'&&ss2=='F')||(ss2=='D'&&ss1=='F')))){
                    cout<<"1110\n";
                    return 0;
                }
                else cout<<1111<<"\n";
            }
        }
    }
    return 0;
}
/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。

*/
