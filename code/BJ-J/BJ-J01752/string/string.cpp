#include<bits/stdc++.h>
using namespace std;
char c1[200010];
long long num1[200010];
char c2[200010];
char ce[200010];
long long num2[200010];
long long nume[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long now=0,midid=0;
    for(long long i=1;i<=n;i++){
        cin>>num1[i]>>c1[i];
        now+=num1[i];
    }
    long long mid=now%2==0?now/2:(now+1)/2;
    now=0;
    for(long long i=1;now<mid;i++){
        now+=num1[i];
        midid++;
    }
    int q=0;
    if(now==mid){
        for(long long i=midid+1;i<=n;i++){
            ce[i-midid]=c1[i];
            nume[i-midid]=num1[i];
            q++;
        }
        for(long long i=1;q!=0;i++,q--){
            num2[i]=nume[q];
            c2[i]=ce[q];
        }
    }
    else{
        long long nummidid=num1[midid];
        now-=num1[midid];
        num1[midid]=mid-now;
        for(long long i=midid;i<=n;i++){
            ce[i-midid+1]=c1[i];
            nume[i-midid+1]=num1[i];
            q++;
        }
        for(long long i=1;q!=0;i++,q--){
            num2[i]=nume[q];
            c2[i]=ce[q];
        }
        num2[n-midid+1]=nummidid-num1[midid];
        c2[n-midid+1]=c1[midid];
    }
    now=0;
    long long ans=0;
    for(long long i=1,j=1;i!=midid+1&&j!=n-midid+2;){
        if(c1[i]==c2[j]){
            if(num1[i]==num2[j]){
                i++,j++;
            }
            else if(num1[i]>num2[j]){
                num1[i]-=num2[j];
                j++;
            }
            else{
                num2[j]-=num1[i];
                i++;
            }
        }
        else{
            if(num1[i]==num2[j]){
                ans+=num1[i];
                i++,j++;
            }
            else if(num1[i]>num2[j]){
                num1[i]-=num2[j];
                ans+=num2[j];
                j++;
            }
            else{
                num2[j]-=num1[i];
                ans+=num1[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
