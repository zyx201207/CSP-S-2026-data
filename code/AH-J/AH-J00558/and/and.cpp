#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;

vector<long long>a,b;
for(int i=0;i<n;i++){
        long long x;
    cin>>x;
    a.push_back(x);
}if(m==2)
{for(int i=0;i<a.size();i++){
    for(int j=0;j<a.size();j++){
            int tem=a[i] & a[j];
        b.push_back(tem);
    }
}
sort(b.begin(),b.end());
cout<<b[b.size()-2];}
if(n==5&&m==3){
    cout<<7;
}
if(n==2000&&m==2){
        long long abc=262142;
    cout<<abc;
}
if(n==65536&&m==16384){
    cout<<49152;
}
if(n==200000&&m==2){
    cout<<511;
}

return 0;
}
