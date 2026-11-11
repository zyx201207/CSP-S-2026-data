#include<bits/stdc++.h>
using namespace std;
int c1[110],c2[110];
string s1[5],s2[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n=3;
    cin>>c1[1];
    for(int i=1;i<=n;i++){
		cin>>s1[i];
		}
    cin>>c2[1];
    for(int j=1;j<=n;j++){
		cin>>s2[i];
		}
    if(c1==c2){
        cout<<"1";
        else{
    cout<<"0";
    }
    }
    if(s1[1]==s2[1]&&s1[2]==s2[2]){
    cout<<"1";
    else{
    cout<<"0";
    }
    }
    if(s1[3]<="C"&&s2[3]<="C"||s1[3]>="C"&&s2[3]>="C"){
    cout<<"1";
    else{
    cout<<"0";
    }
    }
    if(s1[3]-"1"==s2[3]||s1[3]+"1"==s2[3]){
		cout<<"1";
}else{
    cout<<"0";
}
}
