#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool compare(string s1,string s2){
    return ((s1.size()==s2.size()) ? s1==s2:false);
}
string solve(){
    string cx1,cx2,zw1,zw2;
    cin>>cx1>>zw1>>cx2>>zw2;
    if(cx1!=cx2)
        return "0000";
    if(!(zw1[0]==zw2[0]&&zw1[1]==zw2[1]))
        return "1000";
    if(!((zw1[2]<='C'&&zw2[2]<='C')||(zw1[2]>='D'&&zw2[2]>='D')))
        return "1100";
    if(max(zw1[2]*1,zw2[2]*1)-min(zw1[2]*1,zw2[2]*1)!=1)
        return "1110";
    return "1111";
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cout<<solve();
    return 0;
}