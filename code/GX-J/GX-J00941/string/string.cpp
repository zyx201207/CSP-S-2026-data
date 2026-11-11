#include<iostream>
#include<string>
using namespace.std;
int main(){
    string s,s1;
    char g;
    int p,q,a[100000],n,u;
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>a;
    cin>>g;
    for(int i1=0;i1<a;i1++){
        s=s+g;
    }
    }
for(int i=s.size()-1;i>=0;i--){
    s1[p]=s[i];
    p++;
}
for(int i=0;i<s.size();i++){
    if(s[i]!=s1[i])
    q=1;
}
if(q!=1)
cout<<"0";
else{
for(int i=0;i<s.size;i++){
    if(s[i]!=s1[i])
    u++;
    }
    cout<<u;
}

















}
















return 0;
}
