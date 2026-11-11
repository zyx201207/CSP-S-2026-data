#include<bits/stdc++.h>
using namespace std;
string a1,a2,s1,s2;
bool ans;
int side1,side2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1;
    cin>>a1;
    cin>>s2;
    cin>>a2;
    if(s1 != s2){
        cout << "0000";
        return 0;
    }
    if(a1[0] != a2[0] || a1[1] != a2[1])
    {
        cout << "1000";
        return 0;
    }
    if('A'<=a1[2]&&a1[2]<='C') side1 = 1;
    else side1 = 2;
    if('A'<=a2[2]&&a2[2]<='C') side2 = 1;
    else side2 = 2;
    if(side1 != side2)
    {
        cout << "1100";
        return 0;
    }
    if(a1[2]+1==a2[2]||a1[2]-1==a2[2])
    {
        cout << "1111";
    }
    else cout<<"1110";
    return 0;
}
