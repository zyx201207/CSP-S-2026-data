#include<bits/stdc++.h>
using namespace std;
bool same(string a,string b){
    if(a.size()!=b.size()){
        return false;
    }else{
        for(long long i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int a[4]={0};
    string o[8]={"AB","BA","AC","CA","BC","CB","DF","FD"};
    string cnt;
    if(same(c1,c2)){
        a[0]=1;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1] && a[0]==1){
        a[1]=1;
    }
    for(long long i=0;i<8;i++){
        cnt=o[i];
        if(s1[2]==cnt[0] && s2[2]==cnt[1] && a[1]==1){
            a[2]=1;
        }
    }
    if(abs(s1[2]-s2[2])==1 && a[2]==1){
        a[3]=1;
    }
    if(s1[2]=='C' && s2[2]=='D' || s1[2]=='D' && s2[2]=='C'){
        a[3]=0;
    }
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
