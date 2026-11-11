#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    char b[n];
    long long y=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int r=n-1,l=0;
    while(l<r){
        if(b[l]!=b[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                y+=a[r];
                r--;
            }
            else{
                a[r]-=a[l];
                y+=a[l];
                l++;
            }
        }
        else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else{
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<y;
}
