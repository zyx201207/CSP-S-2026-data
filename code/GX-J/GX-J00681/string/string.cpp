#include<iostream>
using namespace std;
int a[200001];char b[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long n;long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    long long li=0,ri=0;int l=0,r=n-1;
    while(l<r){
        if(b[l]!=b[r]){
            if(a[l]-li==a[r]-ri){
                sum+=a[l];
                l++;r--;
                li=0;ri=0;
            }else if(a[l]-li>a[r]-ri){
                sum+=a[r]-ri;
                li+=a[r]-ri;
                ri=0;
                r--;
            }else {
                sum+=a[l]-li;
                ri+=a[l]-li;
                li=0;
                l++;
            }
        }else{
            if(a[l]-li==a[r]-ri){
                l++,r--;
                li=0;ri=0;
            }else if(a[l]-li>a[r]-ri){
                li+=a[r]-ri;
                ri=0;
                r--;
            }else {
                ri+=a[l]-li;
                li=0;
                l++;
            }
        }
    }
    cout<<sum;
    return 0;
}
