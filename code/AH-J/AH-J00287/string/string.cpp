#include<iostream>
#include<string>
using namespace std;
int main(){
    fropen{'r','string.cpp',std.in};
    fropen{'w','string.cpp',std.out};
    long long n,num,a[1000000005];
    string c,s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    for(int i=1;i<=n/2;i++)}{
        if(s[i]!=s[n-i+1])num++;
    }
    cout<<num;
}
