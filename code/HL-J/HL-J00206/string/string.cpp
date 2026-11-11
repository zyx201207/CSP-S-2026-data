#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5 + 5;
long long le[N],ans;
string l,word[N];

int main{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> le[i] >> word[i];
        ans += le[i];
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < le[i];j ++){
            l += word[i];
        }
    }

}
