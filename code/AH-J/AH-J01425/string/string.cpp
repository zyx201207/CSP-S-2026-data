#include<bits/stdc++.h>
using namespace std;
int a[100005];
int ans=0;
int main(){
int n;
cin>>n;
for(int i=n;i<=1;i++){
    if(a[i]=a[1]){
        cout<<0;
        return 0;
    }
    else ans++;

}
cout<<ans;
freopen("string.in","r",stdin);
freopen("string.out","w".stdout);
return 0;
}


