#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int m,n;
cin>>m>>n;
vector<int> a;
for(int i=0;i<m;i++){
    int r;
    cin>>r;
    a.push_back(r);
} vector<int> b,d;
for(int o=1;o<n;o++){

        if(o==1){
for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
        b.push_back(a[i]&a[j]);

}
}sort(b.begin(),b.end());

for(int j=1;j<b.size();j++){

    if(b[j]==b[j-1]){
        b.erase(b.begin()+j);
    j--;
    }
}
//cout<<b.size()<<" ";
        }
else{
    if(o%2==0){
            for(int i=0;i<b.size();i++){
          for(int j=i+1;j<b.size();j++){
        d.push_back(b[i]&b[j]);

    }sort(d.begin(),d.end());

for(int j=1;j<d.size();j++){
   if(d[j]==d[j-1]){
        d.erase(d.begin()+j);
        j--;
  }
    }
}
for(int j=0;j<b.size();j=j+0){
    b.erase(b.begin());
}
    }
    else{
            for(int i=0;i<d.size();i++){
         for(int j=i+1;j<d.size();j++){
        b.push_back(d[i]&d[j]);

    }sort(b.begin(),b.end());

for(int j=1;j<b.size();j++){
    if(b[j]==b[j-1]){
        b.erase(b.begin()+j);
        j--;
    }
}
for(int j=0;j<d.size();j=j+0){
    d.erase(d.begin());
}
    }
    }
}
}//for(int j=0;j<d.size();j++){
   // cout<<d[j]<<" ";
  // }
if(d.empty()){
    sort(b.begin(),b.end());
    cout<<b[b.size()-1];
}
else{
    sort(d.begin(),d.end());
    cout<<d[d.size()-1];
}

return 0;}
