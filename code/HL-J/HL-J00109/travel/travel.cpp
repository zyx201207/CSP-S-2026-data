#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    cin>>a;
    for(int i = 1;i<=4;i++){
        cin>>a[i];
        if(a[1] == a[3])
           cout<<"1";
        else
           cout<<"0";
        if(a[2]/10 == a[4]/10)
            cout<<"1";
        else
            cout<<"0";
        if(a[2]%10+1 == a[4]||a[2]%10-1 == a[4])
            cout<<"1";
        else
            cout<<"0";
        if(a[2]%10 == 'A'&&a[4]%10 == 'B'||a[2]%10 == 'B'&&a[4]%10 == 'A'||a[2]%10 == 'B'&&a[4]%10 == 'C'||a[2]%10 == 'C'&&a[4]%10 == 'B'||a[2]%10 == 'D'&&a[4]%10 == 'F'||a[2]%10 == 'F'&&a[4]%10 == 'D')
            cout<<"1";
        else
            cout<<"0";

    }
}
