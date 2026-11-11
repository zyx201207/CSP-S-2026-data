#include<bits/stdc++.h>
using namespace std;
char a[200009];
long long b[200009];//abc,123
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long sum=0;
    long long n;cin>>n;long long len=1;
    for(long long i=1;i<=n;i++){
        long long x;char y;
        cin>>x>>y;
        if(y==a[len-1]){b[len-1]+=x;}
        else{a[len]=y;b[len]=x;len++;}
    }
    len-=1;
    for(long long i=1,j=len;;){
            if((i>(len+1)/2)||(j<(len+1)/2))break;
            if(a[i]==a[j]){
                long long c=min(b[i],b[j]);
                b[i]-=c;
                b[j]-=c;
                if(b[i]==0){
                    i++;}
                else if(b[j]==0){
                    j--;}
                else{
                    i++;j--;;
                }
            }
            else{
                long long c=min(b[i],b[j]);
                sum+=c;
                b[i]-=c;
                b[j]-=c;
                if(b[i]==0){
                    i++;
                    a[i]=a[j];}
                else if(b[j]==0){
                    j--;
                    a[j]=a[i];}
                else{
                    i++;j--;
                    a[j]=a[i];
                }

            }
        }
    cout<<sum;
    return 0;
}
