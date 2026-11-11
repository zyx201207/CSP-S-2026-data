#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct m{
    long long t,w,lll;
    char s;
}sl[300000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long cc=0;
    int a;
    cin>>a;;
    string t;
    long long cn=0;
    for(int i=0;i<a;i++){
        long long l;
        char ll;
        cin>>l>>ll;
        sl[i].t=cc;
        cc+=l;
        sl[i].w=cc;
        cc++;
        sl[i].s=ll;
        sl[i].lll=l;
    }
    long long b=cc/2;
    cc--;
    int x=a;
    for(int i=0;i<a;i++){
        if(sl[i].t>b){
            break;
        }
        int now=0;


        for(int j=x-1;j>=0;j--){
            if(sl[i].lll>=sl[j].lll){
                if(sl[i].s!=sl[j].s){
                    cn+=sl[j].lll;
                }
                sl[i].lll-=sl[j].lll;
                sl[j].lll=0;
                now++;
            }else{
                if(sl[i].s!=sl[j].s){
                    cn+=sl[i].lll;
                }
                sl[j].lll-=sl[i].lll;
                sl[i].lll=0;
            }
            if(sl[i].lll<=0){
                break;
            }
        }
        x-=now;
    }
    cout<<cn;
    return 0;
}
