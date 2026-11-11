#include <bits/stdc++.h>
using namespace std;
string fanzhuan(string c){
    for(int i=0;i<c.size();i++){
        if(c[i]!=c[c.size()-1-i]){
            c[c.size-1-i]=c[i];
        }
    }
    return c;
}
int tick(int ack){

}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1001]={};
    string c[1001]={};
    int cnt=0,num=0;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>a[i]>>s;
        cnt+=a[i];
        for(int i=cnt-a[i];i<cnt;i++){
            c[i]=s;
        }
    }
    for(int i=0;i<cnt;i++){
        if(fanzhuan(c)!=c){
            for(int j=0;j<c.size();j++){
                if(c[j]!=c[c.size()-1-j]){
                    c[c.size-1-j]=c[j];
                    num++;
                }
            }
        }
    }
    cout<<num;
    return 0;
}
