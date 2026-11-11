#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(m==1){
        long long maxx=-1;
        for(int i=0;i<n;i++){
            long long nn;
            cin>>nn;
            if(nn>maxx) maxx=nn;
        }
        cout<<maxx;
        return 0;
    }
    if(m==n){
        long long summ=1<<20-1;
        for(int i=0;i<n;i++){
            long long nn;
            cin>>nn;
            summ&=nn;
        }
        cout<<summ;
        return 0;
    }
    if(m==2){
        long long maxx=-1,ss[2005]={};
        for(int i=0;i<n;i++){
            cin>>ss[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((ss[i]&ss[j]) > maxx) maxx=ss[i]&ss[j];
            }
        }
        cout<<maxx;
        return 0;
    }
    cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
