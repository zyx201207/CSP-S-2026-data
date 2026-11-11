#include <bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",sdint);
    freopen("travel.out","w",stdour);
    cin >> c1 << s1 <<c2 <<s2;
    if (c1==c2){
        cout<<"1";
        int s[10]=s1;
        int x[10]=s2;
        if(s[1]==x[1]){
            cout << "1";
            if (s[2]=="F"||s[2]=="D"&&x[2]=="F"&&x[2]=="D")
            {	
                cout << "11";
            }
            else
            {
                COUT << "00";
            }
        }
        else
        {
            cout << "000";
        }
        
    else
    {
        cout << "0000";
    }
}
