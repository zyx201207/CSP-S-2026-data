#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a1,a2,s1,s2;
char c1,c2;
/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻
*/
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>c1>>a2>>s2>>c2;
    if(a1!=a2){
        cout<<"0000";
    }else{
        if(s1!=s2){
            cout<<"1000";
        }else{
            if('A'<=c1&&'C'>=c1&&'A'<=c2&&'C'>=c2){
                if(c1=='A'&&c2=='B'||c2=='A'&&c1=='B'||c1=='C'&&c2=='B'||c2=='B'&&c1=='C'){
                    cout<<"1111";
                }else{
                    cout<<"1110";
                }
            }else if(c1=='D'&&c2=='E'||c1=='E'&&c2=='D'){
                cout<<"1111";
            }else{
                cout<<"1100";
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

