#include<iostream>
using namespace std;
const int N=1e5+1;
long long n,a[N],ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        cout<<"#"<<a[i]<<" "<<c[i]<<"\n";
    }
    long long l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            if(a[l]==a[r]){
                a[l]=0;
                a[r]=0;
                l++,r--;
            }
            if(a[l]<a[r]){
                a[l]=0;
                a[r]-=a[l];
                l++;
            }
        }
        else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            if(a[l]==a[r]){
                ans+=a[l];
                a[l]=0;
                a[r]=0;
                l++,r--;
            }
            if(a[l]<a[r]){
                ans+=a[l];
                a[l]=0;
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
