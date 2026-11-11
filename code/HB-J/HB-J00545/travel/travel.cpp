#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a[6]={"0","A","B","C","D","F"};
    string r1,r2;
    string x1,x2;

    cin >> r1;
    cin >> r2;
    cin >> x1;
    cin >> x2;
    if (r1==x1){
        cout << "1";
    }else{
        cout << "0";
    }

    string tmp1,tmp2;
    tmp1=r2.back();
    tmp2=x2.back();

    if (r2[0]==x2[0] && r2[1]==x2[1]){
        cout << "1";
    }else{
        cout << "0";
    }

    for (int i=0;i<=5;i++){
    if (tmp1==a[i]){
        if ((tmp1=="A"||tmp1=="B"||tmp1=="C")&&(tmp2=="A"||tmp2=="B"||tmp2=="C")){
            cout << "1";
            break;
        }else if((tmp1=="D"||tmp1=="F")&&(tmp2=="D"||tmp2=="F")){
            cout << "1";
            break;
        }else{cout << "0";}
    }}




    for (int i=0;i<=5;i++){
    if (tmp1==a[i]){
        if (a[i+1]==tmp2 || a[i-1]==tmp2){
            cout << "1";
            break;
        }else{cout << "0";}
    }
    }

    return 0;
}
