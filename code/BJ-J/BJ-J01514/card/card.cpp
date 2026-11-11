#include<bits/stdc++.h>
using namespace std;
int a,b;
string c;
int ans[1145140];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        string ioioio;
        cin>>ioioio;
        c+=ioioio;
    }
    int cnt=1;
    string nowl="111";
    while(nowl.size()!=0){
        nowl="";
        for(int i=cnt-1;i<a;i++){
            if(nowl.find(c[i])==-1){
                nowl+=c[i];
            }else{
                string qudiao="";
                for(int p=0;p<nowl.find(c[i]);p++){
                    qudiao[p]=nowl[p];
                }
                nowl=qudiao;
            }
        }
        for(int i=0;i<nowl.size();i++){
            ans[nowl[i]-'0']++;
        }
        cnt++;
    }
    for(int i=1;i<=b;i++){
        cout<<ans[i]<<" ";
        }
    return 0;
}



