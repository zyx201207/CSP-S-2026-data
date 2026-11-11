#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
int a[200001];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>s[i];
    }
    int l=n;
    int i=1;
    while(1){
        if(i>=l){
            break;
        }
        if(s[i]!=s[l]){
            if(a[i]>a[l]){
                a[i]-=a[l];
                sum+=a[l];
                l--;
            }else if(a[i]<a[l]){
                a[l]-=a[i];
                sum+=a[i];
                i++;
            }else{
                a[i]=0;
                sum+=a[l];
                a[l]=0;
                l--;
                i++;
            }
        }else{
            if(a[i]>a[l]){
                a[i]-=a[l];
                l--;
            }else if(a[l]>a[i]){
                a[l]-=a[i];
                i++;
            }else{
                a[i]=0;
                a[l]=0;
                i++;
                l--;
            }
        }
    }
    cout<<sum;
    return 0;
}
