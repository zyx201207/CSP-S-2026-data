#include <bits/stdc++.h>

using namespace std;
string  s1 ,  s2;
int a,b;
int main()
{
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    cin >> a >> s1 >> b >> s2;
    //是否是同一车厢？
    if(a == b){
        cout <<1;
        //是否是同一排？
        if(s1[0]==s2[0] && s1[1] == s2[1]){
            cout << 1;
            //是否是同一侧？
            bool lr1  = 0, lr2 = 0;
            if(s1[2]=='D'||s1[2]=='F') lr1 = 1;
            if(s2[2]=='D'||s2[2]=='F') lr2 = 1;
            if(lr1 == lr2) {
               cout << 1;
               //是否相邻？
               if(s1[2] - s2[2] == 1 ||s1[2] - s2[2] == -1) cout << 1;
               else cout << 0;
            }else cout << "00";
        }else cout << "000";
    }else cout << "0000";
    return 0;
}