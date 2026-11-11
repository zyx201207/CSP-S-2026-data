#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s=0;
    string r1,r2,x1,x2,a,b;
    string c1,c2;
    r2+a=c1;
    x2+b=c2;
    cin>>r1>>c1;
    cin>>x1>>c2;
    if(r1==x1){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    if(r1==x1 and r2==x2){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
     if(r1==x1 and r2==x2 and a==b){
        cout<<'1';
        s+=1;
    }
    else{
        cout<<'0';
    }

    if(s==1 ){
			cout<<'1';
    }
    else{
        cout<<'0';
    }
    return 0;
}

