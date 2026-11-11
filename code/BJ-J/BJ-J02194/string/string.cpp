#include<bits/stdc++.h>
using namespace std;
int a[200008];
char c[200008];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long sum = 0;
    int n;
    cin >> n;
    int n1 = n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];

    }
    long long j = n;
    for(long long i = 1; i <= n / 2; i++){

        if(c[i] != c[j]){
            sum += a[i];

        }
        j--;
    }
     cout <<sum;
    return 0;
}
