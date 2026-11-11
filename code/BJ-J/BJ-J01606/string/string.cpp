#include<iostream>
#include<fstream>
using namespace std;
long long int a[200005],L,n,mid,ct,e=1;
char c[200005],s[2000000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin("string.in");
    ofstream cout("string.out");
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        for(long long int j=e;j<=a[i]-1+e;j++)s[j]=c[i];
        e+=a[i];
    }
    mid=L/2;
    if(L%2!=0)mid++;
    for(long long int i=1;i<mid;i++)if(s[i]!=s[L+1-i])ct++;
    cout<<ct;
    return 0;
}
