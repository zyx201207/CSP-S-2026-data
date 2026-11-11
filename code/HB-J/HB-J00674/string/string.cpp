#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0;
    cin>>n;
    long long t=n+1,f=n-1,z=0;
    long long a[t]={};
    char b[t]={};
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    while(f>z){
        if(b[z]!=b[f]){
            if(a[z]>a[f]){
                num+=a[f];
                a[z]=a[z]-a[f];
                f--;}
            else if(a[z]<a[f]){
                num+=a[z];
                a[f]=a[f]-a[z];
                z++;}
            else if(a[z]==a[f]){
                num+=a[z];
                z++;
                f--;}
        }
        else if(b[z]==b[f]){
            if(a[z]>a[f]){
                a[z]=a[z]-a[f];
                f--;}
            else if(a[z]<a[f]){
                a[f]=a[f]-a[z];
                z++;}
            else if(a[z]==a[f]){
                z++;
                f--;}
        }
    }
    cout<<num;
    return 0;
}
