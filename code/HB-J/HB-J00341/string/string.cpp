#include<bits/stdc++.h>
using namespace std;
int n,a,i,j,l,k;
char c;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
while(n--){
    cin>>a>>c;
    while(a--){
        s=s+c;
    }
}
l=s.size();
for(j=l-1;i<j;i++,j--){
    if(s[i]!=s[j])k++;
}
cout<<k;
return 0;
}

