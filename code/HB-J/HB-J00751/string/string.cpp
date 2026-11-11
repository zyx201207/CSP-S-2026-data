#include <bits/stdc++.h>
using namespace std;
long long a,x=0;
string d;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>a;
for(int i=0;i<a;i++){
    string b;
    long long c;
    cin>>c>>b;
    for(long long j=0;j<c;j++){
        d+=b;
    }
}
long long r=0,l=d.size()-1;
for(long long i=0;i<d.size()-1;i+=2){
    if(d[r]==d[l]){
        continue;
    }
    else{
        x++;
    }
}
cout<<x;
return 0;
}
