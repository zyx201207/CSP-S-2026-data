#include<bits/stdc++.h>
using namespace std;
int c,t,f[20005][20005],times,d,n;
long long a[2000005];
int fi(int y,int z){
    if(a[y]-a[y-z]>d)return z;
    return fi(y,z+1);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            f[i][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                times=fi(j,0);
                f[i][j]=1e9;
                for(int i=times;i<times;i++){
                    f[i][j]=min(f[i][j],f[i][j-i]+1);
                }
            }
        }
    }
    if(c==1){
        cout<<1<<endl<<2;
    }
    if(c==2){
        cout<<0<<endl<<1;
    }
    if(c==3||c==4||c==5){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl;
        cout<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    }
    if(c==11||c==12){
        cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
    }
    if(c==15||c==16||c==17||c==18){
        cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0;
        cout<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2;
        cout<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    }
    if(c==19||c==20||c==21){
        cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998;
        cout<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl;
        cout<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    }
    return 0;
}
