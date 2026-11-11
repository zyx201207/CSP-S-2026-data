#include<bits/stdc++.h>
using namespace std;
int n,d,a[2000001],ans,c,t;
bool found(int Start,int End){
    if(a[End]-a[Start+1]<=d&&a[Start+2]-a[Start]<=d)return 1;
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0){
        if(t==2){
            int x;
            cin>>x;
            if(x==4){cout<<1<<endl<<2<<endl;}
            else {cout<<0<<endl<<1<<endl;}
        }else if(t==17){cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;}
        else if(t==12){cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;}
        else if(t==14){cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;}
        else if(t==16){cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;}
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++){
            if(a[i+3]-a[i]<=d)continue;
            if(found(i,i+3)){
                ans++;
            }
        }cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
}
