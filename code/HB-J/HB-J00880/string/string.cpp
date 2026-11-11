#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    int n;
    cin>>n;
    long long j;
    long long p=1;
    string g;
    string k;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>j>>k;
        if(i==0){
            g=k;
        }
        if(j>=1000000000&&(g!=k)){
            p+=j;

        }
        if(j>=1000000000){
            j=1;
        }

        for(int u=0;u<j;u++){
            a+=k;
        }
    }
    if(a.size()%2==0){
       int biaoji=(a.size()-1)/2,biaojii=(a.size()-1)/2+1;
        while(biaoji-1>=0){
            if(a[biaoji-1]!=a[biaojii-1]){
                sum++;
            }
            biaoji--;
            biaojii++;
        }
    }else{
        int biaoji=(a.size()-1)/2,biaojii=(a.size()-1)/2+2;
        while(biaoji-1>=0){
            if(a[biaoji-1]!=a[biaojii-1]){
                sum++;
            }
            biaoji--;
            biaojii++;
        }
    }
    if(p==1){
        cout<<sum*p;
    }else{
        p--;
        cout<<sum*p;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
