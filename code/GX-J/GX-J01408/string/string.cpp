#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a="",a1;
    int y;cin>>y;
    for(int i=0;i<y;i++){
        int we;cin>>we>>a1;
        for(int j=0;j<we;j++){
            a+=a1;
        }
    }
    if(a.size()%2==0){
        string cq="",ch="";
        int lj1=0,lj2=0;
        for(int i=0;i<a.size()/2;i++){
            cq+=a[i];
        }
        for(int i=a.size()/2;i<a.size();i++){
            ch+=a[i];
        }
        if(ch!=cq){
            for(int i=0;i<cq.size();i++){
                if(cq[i]!=ch[i])lj1++;
            }
            for(int i=0;i<ch.size();i++){
                if(ch[i]!=cq[i])lj2++;
            }
            cout<<min(lj1,lj2);
        }else{
            cout<<0;
        }
    }else{
        string cq="",ch="";
        int lj1=0,lj2=0;
        for(int i=0;i<a.size()/2;i++){
            cq+=a[i];
        }
        for(int i=a.size()/2+1;i<a.size();i++){
            ch+=a[i];
        }
        if(ch!=cq){
            for(int i=0;i<cq.size();i++){
                if(cq[i]!=ch[i])lj1++;
            }
            for(int i=0;i<ch.size();i++){
                if(ch[i]!=cq[i])lj2++;
            }
            cout<<min(lj1,lj2);
        }else{
            cout<<0;
        }
    }
    return 0;
}
