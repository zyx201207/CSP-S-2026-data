#include<bits/stdc++.h>
using namespace std;
int a[1000005];
string s[1000005];
string l={};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(int j=1;j<=a[i];j++){
            l+=s[i];
        }
    }
    if(l.size()%2==0){
        string l1=l.substr(0,l.size()/2),l2=l.substr(l.size()/2,l.size()/2),l3={};
        for(int i=l2.size()-1;i>=0;i--){
            l3+=l2[i];
            }
        for(int i=0;i<=l1.size()-1;i++){
            if(l1[i]!=l3[i]){num++;}
        }
    }
    else{
        string l1=l.substr(0,(l.size()-1)/2),l2=l.substr((l.size()+1)/2,(l.size()-1)/2),l3={};
                for(int i=l2.size()-1;i>=0;i--){
                l3+=l2[i];
                }
                for(int i=0;i<=l1.size()-1;i++){
            if(l1[i]!=l3[i]){num++;}
        }
    }
    cout<<num;
}
