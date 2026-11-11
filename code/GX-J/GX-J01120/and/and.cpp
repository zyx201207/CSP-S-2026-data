#include<bits/stdc++.h>
using namespace std;
long long  n,m;
vector<int>a;
int ans=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
while(n--){
    int s;
    cin>>s;
    a.push_back(s);
}
if(m==2){
    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<a.size()-1;j++){
            int mfy=a[i]&a[j];
            ans=max(ans,mfy);
        }
    }
}
else{
    cout<<0;
    return 0;
}
cout<<ans;
return 0;
}
