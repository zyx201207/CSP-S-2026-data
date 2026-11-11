#include<bits/stdc++.h>
using namespace std;
long long sum;
int main(){
    long long n;
    string a;
    cin >> n;
    for(int i=0;i<n;i++){
        int m;
        string b;
        cin >> m >> b;
        for(int j=0;j<m;j++){
            a+=b;
        }

    }
    string b=a;
    int j=0;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[j]){
            sum++;
        }
        j++;
    }
    cout << sum/2;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    return 0;
}
