#include<bits/stdc++.h>;
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int a,b,c[4]={};
    string a1,b1;
    cin>>a>>a1>>b>>b1;

    if(a==b&&a!=01&&a!=16&&b!=01&&b!=16){
        cout<<1;
        c[0]=1;
    }else cout<<0;

    if(c[0]==1 &&a1[0]==b1[0]&&a1[1]==b1[1]){
        cout<<1;
        c[1]=1;
    }else cout<<0;

    if(c[0]==1 &&c[1]==1){
        if(a1[2]=='D'||a1[2]=='F'){
            if(b1[2]!='D'||b1[2]!='F'){
                cout<<0;
                c[2]=0;
            }
        }else if(b1[2]=='D'||b1[2]=='F'){
            if(a1[2]!='D'||a1[2]!='F'){
                cout<<0;
                c[2]=0;
            }
        }else{
            cout<<1;
            c[2]=1;
        }
    }else cout<<0;

    if(c[0]==1 &&c[1]==1&&c[2]==1){
        if(a1[2]=='D'||a1[2]=='F'){
            cout<<1;
        }
        else if(a1[2]-b1[2]==1||b1[2]-a1[2]==1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }else cout<<0;
    
	return 0;
}
