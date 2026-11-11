#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans1,tot2,sum1,num2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else cout<<0;
    for(int i=0;i<4;i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            ans1+=s1[i];
        }
        if(s2[i]>='0'&&s2[i]<='9'){
            tot2+=s2[i];
        }
        if(s1[i]>='A'&&s1[i]<='Z'){
            sum1+=s1[i];
        }
        if(s2[i]>='A'&&s2[i]<='Z'){
            num2+=s2[i];
        }
    }
    if(ans1==tot2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(ans1==tot2)
    {
        if((sum1>='A'&&sum1<='C')&&(num2>='A'&&num2<='C')){
            cout<<1;
        }
        else if((sum1>='D'&&sum1<='F'`&&(num2>='D'&&num2<='F')){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    if(ans1==tot2){
        if((sum1=='A'&&num1=='B')||(sum1=='B'&&num2=='A')){
            cout<<1;
        }
        else if((sum1=='C'&&num2=='D')||(sum1=='D'&&num2=='C')){
            cout<<1;
        }
        else if((sum1=='E'&&num2=='F')||(sum1=='F'&&num2=='E')){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
