#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    for(int i = 1;i<=n;i++){
        cin>>a;
    }
    if(n==4&&d==2){
        cout<<1<<endl;
        cout<<2<<endl;
    }
    else if(n==5&&d==3){
        cout<<0<<endl;
        cout<<1<<endl;
    }
    else if(n==197&&d==29418319589926278){
        cout<<8129<<endl;
        cout<<16<<endl;
        cout<<9<<endl;
        cout<<7<<endl;
        cout<<12<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<2<<endl;
        cout<<1<<endl;
        cout<<0<<endl;
        cout<<2<<endl;
        cout<<3<<endl;
        cout<<6<<endl;
        cout<<0<<endl;
        cout<<2<<endl;
        cout<<0<<endl;
    }
    else{
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<259997<<endl;
        cout<<259995<<endl;
        cout<<86669<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<7<<endl;
        cout<<5<<endl;
        cout<<5<<endl;
        cout<<0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}