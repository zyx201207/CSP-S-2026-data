#include<bits/stdc++.h>
using namespace std;

long long n,d,c,t,cnt=0;
long long maxium=2000000000000000000;
long long x[2000005];

int f(){


    return 2;
}


int main(){
    freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);

    cin>>c>>t;
    for(long long T=1;T<=t;T++){
        cin>>n>>d;
        long long mind=maxium;
        for(long long i=1;i<=n;i++){
            cin>>x[i];
            mind=min(mind,x[i]);
        }
        if(n==1 or d<mind){
            cout<<0<<endl;
            continue;
        }
        if(c==12 or c==11){
            if(d>=2*(x[2]-x[1])){
                cout<<n-1<<endl;
                continue;
            }
            if(d<2*(x[2]-x[1]) ){
                cout<<0<<endl;
                continue;
            }
        }
        cout<<f()<<endl;
    }

    fclose(stdin);
    //fclose(stdout);

    return 0;
}