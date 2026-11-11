#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int w1,w2;
    char x1[2]={0};
    char x2[2]={0};
    vector<int>p;
    vector<int>q;
    cin>>w1>>x1>>w2>>x2;
    if(w1==w2){
        cout<<"1";
    }else{
        cout<<"0";
    }
    p.push_back(x1[1]);
    q.push_back(x2[1]);
    if(w1==w2 && p==q){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(w1==w2 && p==q){
        if(x1[2]>='c'&&x2[2]>='c'){
        cout<<"1";
        }else if(x1[2]<='D'&&x2[2]<='D'){
        cout<<"1";
        }else{
        cout<<"0";
        }
    }else{
    cout<<"0";
    }
    if(w1==w2 && p==q){
        if(x1[2]>='c'&&x2[2]>='c'){
        if(x1[2]-'1'==x2[2]||x1[2]+'1'==x2[2]){
            cout<<"1";
        }else{
        cout<<"0";
        }
        }else if(x1[2]<='D'&&x2[2]<='D'){
        if(x1[2]-'1'==x2[2]||x1[2]+'1'==x2[2]){
            cout<<"1";
        }else{
        cout<<"0";
        }
        }
    }else{
    cout<<"0";
    }





    fclose(stdin);
    fclose(stdout);
    return 0;
}
