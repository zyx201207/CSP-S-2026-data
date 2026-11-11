#include <bits/stdc++.h>
using namespace std;
long long a,b,c[10010],m[10010],max1=0,max2=0,max3=0,x=0,y=0;
long long awy(int x,int y){
    long long kk[10010],cxy[10010],o=0,q=0;
    long long hh=0;
    while(x>0){

        kk[o]=x%2;
        x=x/2;
        o++;
    }
    while(y>0){

        cxy[q]=y%2;
        y=y/2;
        q++;
    }
    for(int i=0;i<max(o,q);i++){
        if(kk[i]==cxy[i]){
            hh+=pow(2,i);
        }
    }
    return hh;
}

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>a>>b;
for(int i=0;i<a;i++){
    cin>>c[i];
}
sort(c,c+a);
if(b==1){
    cout<<c[a-1];
    return 0;
}
if(b==a){
    for(int i=0;i<a-1;i++){
            c[i]=awy(c[i],c[i+1]);
            cout<<c[i]<<" ";

    }
    cout<<c[a-1];
}
if(b==2){
    for(int i=0;i<a;i++){
            long long d[10010],e[10010];
            max1=0,max2=0,x=0,y=0;
        while(c[i]>0){

            e[x]=c[i]%2;
            c[i]=c[i]/2;
            x++;
        }
        for(int j=i+1;j<a;j++){
            while(c[j]>0){

                d[y]=c[j]%2;
                c[j]=c[j]/2;
                y++;
            }
            int t=max(x,y);
            for(int k=0;k<=t;k++){
                if(d[k]==e[k]){
                    max1+=pow(2,k+1);
                    max2=max(max1,max2);
                }
            }

    }

    }
    cout<<max2;
}
return 0;
}
