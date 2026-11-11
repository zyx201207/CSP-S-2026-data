#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],ans,num;
char c[200005];
long long top=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
    }
    int i=1,i2=n;
    while(top<num){
        if(a[i]>0&&a[i2]>0){
            if(a[i]>a[i2]){

                if(c[i]!=c[i2]){
                    ans+=a[i2];
                }
                a[i]-=a[i2];
                top+=2*a[i2];
                a[i2]=0;

            }else if(a[i]<a[i2]){

                if(c[i]!=c[i2]){
                    ans+=a[i];
                }
                a[i2]-=a[i];
                top+=2*a[i];
                a[i]=0;

            }else{

                if(c[i]!=c[i2]){
                    ans+=a[i];
                }
                top+=a[i]+a[i2];
                a[i]=0,a[i2]=0;

            }
        }
        if(num%2==1&&top+1==num){
            cout<<ans;
            return 0;
        }
        if(num%2==0&&top==num){
            cout<<ans;
            return 0;
        }
        if(a[i]==0&&i<n)i++;
        if(a[i2]==0&&i2>1)i2--;
    }
    cout<<ans<<endl;
    return 0;
}
