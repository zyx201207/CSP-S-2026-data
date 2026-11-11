#include <bits/stdc++.h>
using namespace std;

int n,cnt;
long long mx;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin >> n;
long long num[n+10];
string s[n+10];
for(int i=1;i<=n;i++){
    cin >> num[i] >> s[i];
    mx+= num[i];
}

for(int i=1;i<=n;i++){
    if(s[i]==s[i+1]) {
    num[i+1] += num[i];
    continue;
    }
    if(num[i] >= mx/2 && i<n/2){
        cnt = mx-num[i];
        break;
    }
    if(mx%2!=0){
        cnt = mx/2;
    }
}
cout <<cnt;
return 0;
}
