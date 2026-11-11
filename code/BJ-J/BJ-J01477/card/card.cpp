#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>v(N);
int a[N]={0};
int b[N]={0};
int n,m;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>b[i];
}
int x=0;
for(int i=x;i<n;i++){
v.push_back(b[i]);
 a[b[i]]++;
if(a[b[i]]>1){
    while(a[b[i]]!=1){
            a[v[v.size()-1]]--;
        v.pop_back();
    }
}
x++;
}
for(int i=1;i<=m;i++){
    cout<<a[i]<<" ";
}
return 0;
}
