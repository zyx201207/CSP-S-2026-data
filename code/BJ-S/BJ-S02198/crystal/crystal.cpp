#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[500005],m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
}
    sort(a+1,a+n+1);
    for(int i=1;i>=n;i++){
    while (m>0){
        if (a[i]<a[m+1]{a[i]++;m--;}
        else continue;}
    }
int cnt=0;
    if(m==0){
for(int i=1;i<=n;i++){
if a[i]==a[i+1]cnt++;
else break;}
cout << cnt;}}
return 0;}
