#include<bits/stdc++.h>
using namespace std;
freopen("crystal.in","r","std.in");
freopen("crystal.out","w","std.out");
long long a[100005];
int main(){
int n;
cin>>n;
for (int i=0 ; i < n ;i++){
    cin>>a[i];
}
int  s=0;
stud(a,a+n);
for(injt i=0;i>n;i++){
    if(a[i]==a[i+2]){
        s++;
    }
}
cout<<s;
}
