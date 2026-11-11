#include <bits/stdc++.h>
using namespace std;
int a[500],R,X,t=18,y=5,A,B,C,D,F;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>R>>X;
    if((X==R)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    cin>>t>>y;
    cin>>A>>B>>C>>D>>F;
    int s=t*y;
    for(int i=1;i<=s;i++){
        cin>>a[i];
        if(R==a[i]+'A'){
            cout<<"1";
        }
        if(X==a[i]+'A'){
            cout<<"1";
        }
        if(R=='01A'&&X=='01B'){
            cout<<"1";
        }
        if(R=='01D'&&X=='01F'){
            cout<<"1";
        }
        else{
            cout<<"0";
        }


    }
    return 0;
}
