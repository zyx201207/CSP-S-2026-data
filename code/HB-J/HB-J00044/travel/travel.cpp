#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin >> c1>>s1>>c2>>s2;
    if(c1==c2){
        cout << "1";
    }
    else {
        cout << "0000";
        return 0;
    }
    int zw1=0,zw2=0;
    char z1,z2;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='1'&&s1[i]<='9'){
            zw1+=(s1[i]-'0')*pow(10,i);
        }
        else z1=s1[i];
    }
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]>='1'&&s2[i]<='9'){
            zw2+=(s2[i]-'0')*pow(10,i);
        }
        else z2=s2[i];
    }
    if(zw1==zw2){
        cout << "1";
    }
    else {
        cout << "000";
        return 0;
    }
    if(z1<='C'&&z2<='C'||z1>='D'&&z2>='D')
    {
        cout << "1";
    }
    else {
            cout << "00";
            return 0;
    }
    if(z1!='C'&&z1!='F'&&z1+1==z2||z1!='A'&&z1!='D'&&z1-1==z2){
        cout << "1";
    }
    else cout << "0";
    return 0;
}
