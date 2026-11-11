 #include<bits/stdc++.h>
using namespace std;
string s,as;
long long x,y,z,m;
long long a[1000005];
char b[1000005];
int main(){
//freopen("string.out","w",stdout);
int n;
cin>>n;
for(int i=0;i<n;i++){
cin>>a[i]>>b[i];
m+=a[i];
for(int j=0;j<=a[i];j++){
s+=b[i];
}
}
z=m;
//as=reverse(s.begin(),s.begin()+m);
for(long long i=0;i<m;i++){
for(long long j=s.size()-1;j>=0;j--){
as+=s[j];
}
if(s==as){
cout<<x;
return 0;
}
if(s[m]!=a[i]){
s[m]=a[i];
m--;
x++;
}
}
return 0;
}
 
                        
