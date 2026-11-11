#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m; cin>>n>>m;
vector<int>arr(n,0);
vector<int>cx(m+1,-1);
for(int i=0;i<n;++i){
cin>>arr[i]; cx[arr[i]]=0;
}

for(int i=0;i<n;i++){
vector<int>brr;
for(int j=i;j<n;j++){
brr.push_back(arr[j]);
}
vector<int>crr;
for(int k=0;k<brr.size();k++){
int t=brr[k];
int w=-1;
int f=1;
for(int ko=0;ko<crr.size();ko++){
if(crr[ko]==t){
w=ko;
f=0;
break;
}
}
if(f==0){
vector<int>krr;
for(int a=0;a<w;a++){
krr.push_back(crr[a]);
}
crr=krr;
}
crr.push_back(t);
}
int cnt=0;
for(auto ip:crr){
cx[ip]++;
}
}
for(auto l:cx){
if(l!=-1) cout<<l<<' ';
}
return 0;
} 
