#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        long long int m,a[1000005];
        int n;
        cin>>n>>m;
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int sum=0;
        //if(n==4){
            for(int j=0;j<n-3;j++){
                if(abs(a[j]-a[j+1])<=m&&abs(a[j+2]-a[j+1])<=m&&abs(a[j+2]-a[j+3])<=m){
                    if(abs(a[j]-a[j+1])==abs(a[j+2]-a[j+3])){
                        sum++;
                    }
                }
            }
            cout<<sum<<endl;
        //}
        /*
        if(n>=5){
            for(int j=0;j<n-4;j++){
                if(j==0){
                    if(abs(a[j]-a[j+1])<=m&&abs(a[j+2]-a[j+1])<=m&&abs(a[j+2]-a[j+3])<=m){
                        if(abs(a[j]-a[j+1])==abs(a[j+2]-a[j+3])&&abs(a[j]-a[j+1])!=abs(a[j+3]-a[j+4])){
                            sum++;
                        }
                    }
                }else if(j==n-5){
                    if(abs(a[j]-a[j+1])<=m&&abs(a[j+2]-a[j+1])<=m&&abs(a[j+2]-a[j+3])<=m){
                        if(abs(a[j]-a[j+1])==abs(a[j+2]-a[j+3])&&abs(a[j]-a[j+1])!=abs(a[j-1]-a[j])){
                            sum++;
                        }
                    }
                }else{
                    if(abs(a[j]-a[j+1])<=m&&abs(a[j+2]-a[j+1])<=m&&abs(a[j+2]-a[j+3])<=m){
                        if(abs(a[j]-a[j+1])==abs(a[j+2]-a[j+3])){
                            sum++;
                        }
                    }
                }
            }
            cout<<sum<<endl;
        }
        */
    }
    return 0;
}
