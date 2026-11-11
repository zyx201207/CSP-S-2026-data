#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[210000],a1[210000];
    char c[210000],c1[210000];
    long long l=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        a1[n-i+1]=a[i];
        c1[n-i+1]=c[i];
        l+=a[i];
    }
    long long sum=0,sum1=0,sum2=0,nj=1,x=0,j=1;
    for(int i=1;i<=n;i++){

        sum1+=a[i];
        for(;j<=n;j++){
            sum+=a1[j];
            if(sum>sum1){
                x=sum-sum1;
                //j--;
                sum=sum1;
                if(c[i]==c1[j]){
                    sum2+=a1[j]-x;
                }
                a1[j]=x;

                break;
            }
             if(c[i]==c1[j]){
                sum2+=a1[j];
             }

        }

    }
    cout<<(l-sum2)/2;
    return 0;
}
