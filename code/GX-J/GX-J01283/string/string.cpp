#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
preopen('string.in','r',stdin);
preopen('string.out','w',stdout);
cin>>n;
int a[10000];
char c;
string s;
for(int i=0;i<n;i++){
cin>>a[i];
cin>>c;
for(int j=0;j<a[i];j++){
s=s+c;
}
}
long long s=0;
for(int i=0;i<s.size()/2;i++){
if(s[i]!=s[s.size()-i]){
s++;
}
}
cout<<s;



return 0;
}
