#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,d;long long x[2000020];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    int c,t;
    cin>>c>>t;
    if(c==0){

    }
    if(c>0&&c<=10){
        //baoli
        for(int i=0;i<t;i++){

        }
    }
    if(c>=11&&c<=12){
        //dengcha
        for(int i=0;i<t;i++){
            cin>>n>>d;
            long long ans=0;
            for(int j=1;j<=n;j++){
                cin>>x[j];
            }
            if(((x[3]-x[1])>d)||(x[4]-x[1]<=d)){
                cout<<0<<endl;
            }else{
                for(int i=1;i<=n-3;i++){
                    ans+=((n-i-1)>>1);
                }
                cout<<ans<<endl;
            }
        }
    }
    if(c>=13&&c<=14){
        for(int i=0;i<t;i++){

        }
    }
    if(c>=15&&c<=18){

    }
}
