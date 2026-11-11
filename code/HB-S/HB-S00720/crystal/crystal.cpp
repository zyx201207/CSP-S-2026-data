#include <bits/stdc++.h>
using namespace std;
long long num1,cs,nl[10010],db[10010],zh,zd,gs=0;
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>num1>>cs;
zh=cs;
zd=cs;
for(int i=0;i<num1;i++){
    cin>>nl[i];
    zh+=nl[i];
}
zh/=num1;
sort(nl,nl+num1);
for(int i=0;i<num1;i++){
    if(nl[i]>zh){
        break;
    }
    db[i]=nl[i];
    gs++;
    zd+=db[i];
}
zd/=gs;
cout<<gs;



return 0;}
