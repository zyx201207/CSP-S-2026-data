#include<bits/stdc++.h>
using namespace std;
int n , m;
string s[200002];
string max = '0';
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < m;j++){
            if(s[i] & s[j] >= max){
                max = s[i] & s[j];
            }
        }
    }
    cout << max;
    return 0;
}

