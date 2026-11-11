#include <bits/stdc++.h>
using namespace std;
struct A{
    string c;
    int d;
};
A a[200005],b[200005];long long n,m,ans,an;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i].d>>b[i].c;
    }
    n=m;
    int p=1;a[1].c=b[1].c;
    a[1].d=b[1].d;an+=b[1].d;
    for(int i=2;i<=m;i++){
            an+=b[i].d;
        if(a[p].c==b[i].c){
            a[p].d+=b[i].d;
        }
        else{
            p++;
            a[p].c==b[i].c;
            a[p].d+=b[i].d;
        }
    }
    n=p;
    int w1=0,w2=0;


        int j=n;
        for(int i=1;w1<=an/2 && w2<=an/2 && i<=n && j>0;){

                int q=a[i].d,w=a[j].d;
                w1+=q;w2+=w;
                if(q<0){

                    i++;
                    a[i].d+=a[i-1].d;
                }
                else if(w<0){
                    j--;
                a[j].d+=a[j-1].d;
                }
                else{
            if(a[i].c!=a[j].c)ans+=max(q,w);
            else{

                ans+=abs(a[i].d-a[j].d);
            }
        if(q<w && w1<=an/2){
            a[i+1].d-=abs(a[i].d-a[j].d);

        }
        if(q>w && w2<=an/2){
            a[j].d-=abs(a[i].d-a[j].d);

        }
        j--;i++;
                }


        }


    cout<<ans;
    return 0;
}
