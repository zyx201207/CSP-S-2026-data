#include<bits/stdc++.h>
using namespace std;
char a[10],b[10],c[10],d[10];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
for(int i=1;i<=2;i++){
    cin>>a[i];
}
for(int i=1;i<=3;i++){
    cin>>b[i];
}
for(int i=1;i<=2;i++){
    cin>>c[i];
}
for(int i=1;i<=3;i++){
    cin>>d[i];
}
for(int i=1;i<2;i++){
    if(a[i]==c[i]&&a[i+1]==c[i+1]){
        cout<<"1";
    }else {
    cout<<"0000";
    return 0;
    }
}
for(int i=1;i<2;i++){
    if(b[i]==d[i]&&b[i+1]==d[i+1]){
        cout<<"1";
    }else {
    cout<<"000";
    return 0;
    }
}
if(b[3]-'c'<=0&&d[3]-'c'<=0){
    cout<<"1";
    }else if(b[3]-'c'>0&&d[3]-'c'>0){
        cout<<"11";
        return 0;
    }else {
    cout<<"00";
    return 0;
    }
    if(b[3]-d[3]==1||d[3]-b[3]==1){
        cout<<"1";
            }else {
            cout<<"0";
            }
return 0;
}
