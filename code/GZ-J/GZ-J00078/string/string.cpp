#include <bits/stdc++.h>//GZ-J00078  威宁自治县牛棚中学  张晨希
using namespace std;
int n,a,num;
string s,c;
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    cin >> n;
    if (n==1){
        cout << 0;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        cin >> a >> c;
        for (int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    string e;
    for (int i=s.length()-1;i>=0;i++)
    {
        e+=s[i];
    }
    if (s==e) num=0;
    else{
        for (int i=0;i<s.length();i++)
        {
            if (c[i]!=s[i]) num++;
        }
    }
    cout << num/2;
    return 0;
}
