#include<bits/stdc++.h>
using namespace std;
int n,m;
string s="";
long long sum[300015];
void stl(string k){
    int l=k.size();
    int p=k.size();
    int sig[l]={0};
    for(int i=0;i<l;i++,l=k.size()){
        if(!sig[k[i]]){
            sig[k[i]]=i;
            continue;
        }
        k.replace(sig[k[i]],i-sig[k[i]],"");
        i=sig[k[i]];
    }
    for(int i=0;i<k.size();i++){
        sum[k[i]]++;
    }
    stl(k.substr(1,p-2));
}
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        s=s+c;
    }
    stl(s);
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
}
