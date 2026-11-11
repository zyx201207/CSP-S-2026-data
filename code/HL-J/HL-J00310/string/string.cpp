#include<bits/stdc++.h>
using namespace std;
int main (){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
int x[200310];
char a[100];
cin>>n;
for(int i=1;i<=n;i++){
    cin>>x[i-1];
    cin>>a[i-1];

}
if(a[0]==a[1]==a[2]==a[3]==a[4]){
cout<<"0";
}
else{
    cout<<"2";
}

return 0;
}
