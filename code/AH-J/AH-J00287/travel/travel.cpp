#include<iostream>
#include<string>
using namespace std;
int main(){
    fropen{'r','travel.cpp',std.in};
    fropen{'w','travel.cpp',std.out};
    int a,b,c,d;
    string x,y;
    cin>>a>>b>>x>>c>>d>>y;
    if(a==c){
        cout<<1;
        if(b==d){
            cout<<1;
            if((x<'D'&&y<'D')||(x>'C'&&y>'C')){
                cout<<1;
                if(x-y==1||y-x==1)cout<<1;
                else cout<<0;
            }
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
}
