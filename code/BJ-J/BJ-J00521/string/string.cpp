#include<iostream>
using namespace std;
long long n,a[1000005],num[1000005],cnt,sum;
char b[1000005],h[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    num[1]=a[1];
    h[1]=b[1];
    cnt=1;
    for(int i=2;i<=n;i++){
        if(b[i]==h[cnt]){
            num[cnt]+=a[i];
        }
        else{
            h[++cnt]=b[i];
            num[cnt]=a[i];
        }
    }
    for(int i=1,j=cnt;i<j;i=i){
        if(h[i]==h[j]){
            if(num[i]>num[j]){
                //sum+=num[i]-num[j];
                num[i]-=num[j];
                j--;
            }
            else if(num[i]<num[j]){
                //sum+=num[j]-num[i];
                num[j]-=num[i];
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        else{
            if(num[i]>num[j]){
                sum+=num[j];
                num[i]-=num[j];
                j--;
            }
            else if(num[i]<num[j]){
                sum+=num[i];
                num[j]-=num[i];
                i++;
            }
            else{
                sum+=num[i];
                i++;
                j--;
            }
        }
    }
    cout<<sum;
    return 0;
}
