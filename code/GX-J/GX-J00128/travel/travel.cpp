#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a[10005]={"A","B","C","D","F"};
    string b[10005]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"};

    string c1,c2;
    for(int j=1;j<=5;j++){
        for(int i=1;i<=18;i++){

        string s1=b[i]+a[j];
        cin>>c1>>s1>>c2;

        if(c1==b[0]||c2==b[0]||c1==b[15]||c2==b[15]||c1!=c2) cout<<"0";
        if (c1==c2) cout<<"1";



        for(int k=1;k<=5;k++){
            for(int l=1;l<=18;l++){
                string s2=b[k]+a[l];
                cin>>s2;
                if(b[k]==b[i])cout<<"1";
                else cout<<"0";
                if(b[k]==b[3]&&b[i]==b[4]||b[k]==b[4]&&b[i]==b[3])cout<<"1";

                if(a[j]==a[l])cout<<"1";
                else cout<<"0";
                }
            }
        }

        }
    return 0;

}
