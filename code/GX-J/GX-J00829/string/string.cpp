#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,d=0,a_num=0,a_c,num;
    cin>>n;
    int a[1005]={},c;
    char s[1005]={};
    string s2;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>s[i];
    }
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])continue;
        else c++;
    }
    if(c==0)cout<<0;
    for(int i=0;i<1005;i++){
        a_num+=a[i];
    }
    int bf=a_num;
    for(int i=0;i<a_num;i++){
        for(int j=0;j<a[i];j++){
            s2[j]=s[i];
        }
    }
    for(int i=(a_num/2);i>=0;i++){
        if(s2[(a_num/2)-i]==s2[(a_num/2)+i]){
            num++;
        };
    }
    cout<<num;
    return 0;
}
