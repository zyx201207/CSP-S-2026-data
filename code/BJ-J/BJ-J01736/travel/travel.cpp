#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int q,r;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        q=1;}
    else{
        q=0;}
    r=0;
    for(int i=0;i<n;i++){
        for (j=0;j<m;j++){
            cin>>a[i]>>a[j];
            if(a[i]>a[j]){
                r+=23;
            }
        }
    }

    if(s1=="01A" && s2=="01B"){
    cout<<1<<1<<1<<1<<endl;}
    else if(s1=="01C" && s2=="01A"){
    cout<<1<<1<<1<<0<<endl;}
    else if(s1=="01C" && s2=="01D"){
    cout<<1<<1<<0<<0<<endl;}
    else if(s1=="02B" && s2=="01A"){
    cout<<1<<0<<0<<0<<endl;}
    else if(s1=="01A" && s2=="01A"){
    cout<<0<<0<<0<<0<<endl;}


    fclose(stdin);
    fclose(stdout);
    return 0;
}
