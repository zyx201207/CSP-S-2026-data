
#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
string q;
char s[100005];
int a[100005];
int n;
int l=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    l+=a[i];
    cin>>s[i];
    for(int j=1;i<=a[i];j++){
    q+=s[i];

}
}
for(int i=1;i<=q.size();i++){
    if(q[i]!=a[q.size()-i+1]){}
    l++;
}
cout<<l;
return 0;
}
