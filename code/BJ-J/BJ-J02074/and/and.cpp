#include<bits/stdc++.h>
using namespace std;
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int a[99],b,c;
string w,e,wez="",z="";
string er(int u){
    string q="";
    while(u!=0){
        if(u%2==0){
            q="0"+q;
        }else{
            q="1"+q;
        }
        u=u/2;
    }
    return q;
}
int shi(string u){
    int q=0;
    int k=0;
    while(u!=""){
        if(u[k]==0){
            q=q*2;
        }else{
            q=q+1;
            q=q*2;

        }
        k++;
    }
    return q;
}
void
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            w=er(a[i]);
            e=er(a[j]);
            for(int l=0;l<n;l++){
                if(w[l]==e[l]&&e[l]=="1"){
                    wez=wez+"1";
                }else{
                    wez=wez+"0";
                }
            }
            if(wez>z){
                z=wez;
            }
        }
    }
    cout<<shi(z);
    return 0;
}
