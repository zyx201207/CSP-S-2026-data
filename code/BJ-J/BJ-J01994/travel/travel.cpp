#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,a2;
int aa,ab;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>a2;
    if(a==b)cout<<'1';
    else{
        cout<<"0000";
        return 0;
    }
    if(a1[0]==a2[0]&&a1[1]==a2[1])cout<<'1';
    else{
        cout<<"000";
        return 0;
    }
    aa=a1[2]-'A';
    ab=a2[2]-'A';
    if(ab<=2&&aa<=2&&(aa+1==ab||aa-1==ab)){
        cout<<"11";
    }else if(aa>=3&&ab>=3)cout<<"11";
    else if(ab<=2&&aa<=2&&(aa+2==ab||aa-2==ab)){
        cout<<"10";
    }else cout<<"00";
    return 0;
}
