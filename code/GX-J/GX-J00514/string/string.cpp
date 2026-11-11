#include<bits/stdc++.h>
using namespace std;
long long a[1000000], cnt, sum;
char c[1000000];
int main(){
freopen("string.in","s",stdin);
freopen("string.out","w",stdout);
long long n;
cin >> n;
string s;
for(long long i = 0 ;i < n ; i++){
    cin >> a[i] >> c[i];
    for(long long j = 0 ; j < a[i] ; j++){
        s += c[i];
    }
}
sum = s.size();
for(long long k = 0 ; k < sum / 2; k++){
    int i = 0, j = sum - 1;
    if(s[i] != s[j])
        cnt++;
    i++;
    j--;
}
cout << cnt;
return 0;
}
