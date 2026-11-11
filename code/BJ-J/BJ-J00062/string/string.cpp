#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    char c[4189998],d[4189998];
    long long wei=0;
    long long N;
    char mi;
    for(long long i=0;i<n;i++){
        cin>>N>>mi;
        if(N+wei>4189998){
            if(N>4189998){
                for(long long j=wei-4189998;j<N+wei-4189998;j++){
                    d[j]=mi;
                }
            }else{
                long long ccnt=0;
                for(long long j=wei;j<4189998;j++){
                    c[j]=mi;
                    ccnt++;
                }
                for(long long j=0;j<N-ccnt;j++){
                    c[j]=mi;
                }
            }
        }else{
            for(long long j=wei;j<N+wei;j++){
                c[j]=mi;
            }
        }
        wei+=N;
    }
    long long cnt=0;
    if(wei>4189998){
        for(long long i=0;i<wei/2;i++){
            if(wei-i-1>4189998){
                if(c[i]!=d[wei-i-1-4189998]){
                    c[i]=d[wei-i-1-4189998];
                    cnt++;
                }
            }else{
                if(c[i]!=c[wei-i-1]){
                    c[i]=c[wei-i-1];
                    cnt++;
                }
            }
        }
    }else{
        for(long long i=0;i<wei/2;i++){
            if(c[i]!=c[wei-i-1]){
                c[i]=c[wei-i-1];
                cnt++;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
