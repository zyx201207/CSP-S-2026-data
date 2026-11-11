#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
bool c,pa,ce,s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    //chexiang
    if(c1==c2){
        cout<<1;
        c=1;
    }else{
        cout<<0;
    }
    //pai
    if(c&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        pa=1;
    }else{
        cout<<0;
    }
    //ce
    int l1=s1[2]-'A';
    int l2=s2[2]-'A';
    bool lt=0,rt=0;
    if(l1>=0&&l1<=2&&l2>=0&&l2<=2){
        lt=1;
    }
    if(l1>=3&&l1<=5&&l2>=3&&l2<=5){
        rt=1;
    }
    if(c&&pa&&(lt||rt)){
        cout<<1;
        ce=1;
    }else{
        cout<<0;
    }
    //xianglin

    if(lt&&abs(l1-l2)==1){
        s=1;
    }
    if(rt&&abs(l1-l2)==2){
        s=1;
    }
    if(c&&pa&&ce&&s){
        cout<<1;
    }else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
