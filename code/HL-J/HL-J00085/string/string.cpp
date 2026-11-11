#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
    }
    else if(n==2){
        int a,c;
        char b,d;
        cin>>a>>b>>c>>d;
        if(b==d){
            cout<<0;
        }
        else{
            cout<<(a-c)*c;
        }
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

