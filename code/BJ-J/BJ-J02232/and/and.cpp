#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,max=LONG_MIN,p=0,q=0;
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==2){
        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n;j++){
                if(a[i]==a[j]&&a[i]>max)max=a[i];
            }
        }
        cout<<max;
    }else{
        long long m1=m;
        while(m){
            bool b[n];
            if(m==m1){
                for(long long i=0;i<n;i++){
                    b[n]=true;
                }
            }
            long long c;
            for(long long i=0;i<n;i++){
                for(long long j=i+1;j<n;j++){
                    c=a[i]&a[j];
                    if(c>max&&b[i]&&b[j]){
                        max=c;
                        b[p]=true;
                        b[q]=true;
                        p=i;
                        q=j;
                        b[i]=false;
                        b[j]=false;
                    }
                }
            }
            m--;
        }
        cout<<max;
    }
    return 0;
}