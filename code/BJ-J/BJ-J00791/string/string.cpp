#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,l=0;
struct node{
    int a;
    char c;
};
node s[200010],lef[200010],rig[200010];
int inxl,inxr;

signed main(){
    freoepn("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        int a;char c;
        cin>>a>>c;
        s[i]={a,c};
        l+=a;
    }

    for(int i=1;i<=n;i++){
        int posl=0;
        if(posl+s[i].a<lon/2){
            lef[++inxl]=a[i];
            posl+=s[i].a;
        }
        else{
            lef[++inxl]={l/2-posl,s[i].a};
            int posr=0;
            for(int j=n;j>i;j--){
                posr+=s[i].a;
                rig[++inxr]=s[i];
            }
            rig[++inxr]={l/2-posr,s[i].a};
            break;
        }
    }
    string lefs="";
    for(int i=1;i<=inxl;i++){
        for(int j=1;j<=lef[i].a;j++) lefs+=lef[i].c;
    }
    string rigs="";
    for(int i=1;i<=inxr;i++){
        for(int j=1;j<=rig[i].a;j++) rigs+=rig[i].c;
    }
    int ans=0;
    for(int i=1;i<=l/2;i++){
        if(lefs[i]!=rigs[i]) ans++;
    }
    cout<<ans<<endl;
}