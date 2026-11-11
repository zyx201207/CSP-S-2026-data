
#include<iostream>
using namespace std;
int main(){
    fropen{'r','and.cpp',std.in};
    fropen{'w','and.cpp',std.out};
    int n,m
    long long a[10000000000];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-1;i++){
        if(a[i]<a[i+1]){
            int t=a[i];
            a[i]=a[i+1];
            a[i+1]=t;
        }
    }
    int sum=a[i];
    for(int i=1;i<=m-1;i++){
        sum=sum&a[i+1];
    }
    cout<<sum;
}
