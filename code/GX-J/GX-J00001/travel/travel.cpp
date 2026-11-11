#include<bite/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",strout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool flag=1;
    if(flag==1&&c1==c2)cout << 1;
    else{
        flag=0;
        cout << 0;
    }
    if(flag==1&&s1[0]==s2[0]&&s1[1]==s2[1])cout << 1;
    else{
        flag=0;
        cout << 0;
    }
    if(flag==1&&((s1[2]<='c'&&s2[2]<='c')||(s1[2]>'c'&&s1[2]>'c')))cout << 1;
    else{
        flag=0;
        cout << 0;
    }
    if(flag==1&&abs(int(s1[2]-s2[2]))==1)cout << 1;
    else{
        flag=0;
        cout << 0;
    }
    return 0;
}
