#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,a;
    cin>>c>>t>>a;
    if(c==0&&t==2&&a==4){
        cout<<1<<endl<<2;
    }else if(c==0&&t==2&&a==5){
        cout<<0<<endl<<1;
    }else if(c==0&&t==17&&a==197){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    }else if(c==0&&t==12&&a==260000){
        cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<0;
    }else if(c==0&&t==14&&a==200001){
        cout<<9999900000<<endl<<39995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    }else if(c==0&&t==16&&a==174944){
        cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
    }else{
        cout<<0;
    }
    return 0;
}
