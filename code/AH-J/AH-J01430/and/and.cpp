#include<bits/stdc++.h>
using namespace std;
int a[100000005],b[100000005];
int main(){
    freopen("and5.in","r",stdin);
    freopen("and5.out","w",stdout);
    int n,m,sum=0;
    cin>>n>>m;
    int max1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(m==1){
            while(a[i]>0){
                sum=sum+a[i]%2;
                a[i]/=2;
                sum*=10;
            }
        }
        if(m==2){
            int j=1;j++;
            while(a[i]>0){
                sum+=a[i]%2&a[j]%2;
                a[i]/=2;
                a[j]/=2;
                sum*=10;
            }
        }
        max1=max(max1,sum);
        sum=0;
    }
    int i=1;
    int max2=0;
    while(max1>0){
        max2+=(max1%10)*pow(2,i);
        max1/=10;
        i++;
    }
    cout<<max2<<endl;
}
