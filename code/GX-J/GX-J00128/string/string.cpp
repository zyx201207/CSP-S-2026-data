#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string a[10005]={"A","B","C","D","F"};
    string b[10005]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"};

    string c1,c2;
    for(int j=1;j<=5;j++){
        for(int i=1;i<=18;i++){

        string s1=b[i]+a[j];
        cin>>c1>>s1>>c2;



        if(c1==b[0]||c2==b[0]||c1==b[15]||c2==b[15]||c1!=c2) cout<<"0";
        if (c1==c2) cout<<"1";
        string s2;
        cin>>s2;
        if(s2==b[i]+a[j-1]||s2==b[i]+a[j+1]) cout<<"1";
        }
    }








    return 0;

}
