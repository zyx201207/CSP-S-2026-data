#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    string tp1,tp2;
    char zw1,zw2;
    for(int i=0;i<3;i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            tp1+=s1[i];
        }
        else{
            zw1=s1[i];
        }
    }
    for(int i=0;i<3;i++){
        if(s2[i]>='0'&&s2[i]<='9'){
            tp2+=s2[i];
        }
        else{
            zw2=s2[i];
        }
    }
    if(tp1==tp2) cout<<1;
    else{
        cout<<"000";
        return 0;
    }

    if(zw1=='D'&&zw2=='C'){
        cout<<"00";
        return 0;
    }
    else if(zw2=='D'&&zw1=='C'){
        cout<<"00";
        return 0;
    }
    else cout<<1;
    char aaa[5]={'A','B','C','D','F'};
    int x1,x2;
    for(int i=0;i<5;i++){
        if(zw1==aaa[i]) x1=i;
        if(zw2==aaa[i]) x2=i;
    }
    if(x1+1==x2||x2+1==x1){
        cout<<1;
    }
    else cout<<0;
return 0;
}
