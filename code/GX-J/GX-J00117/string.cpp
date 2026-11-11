#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m;
int cnt=0;
int sum=0;
char a;
string s='';
cin>>n;
for(int i=1;i<=n;i++){
    cin>>m>>a;
    cnt+=m;
    for(int j=1;j<=m;j++){
    string s+=a;

}
}
if(s.size()%2==1){
    for(int i=0;i<=(m-1)/2;i++){
        if(s[i]==s[m-i-1]){
            sum++;
        }
    }
    sum=(m-sum*2)/2;
    cout<<sum;
    return 0;
}
else{
   for(int i=0;i<=m/2;i++){
        if(s[i]==s[m-i-1]){
            sum++;
        }
    }
    sum=(m-sum*2)/2;
    cout<<sum;
    return 0;
}
}

