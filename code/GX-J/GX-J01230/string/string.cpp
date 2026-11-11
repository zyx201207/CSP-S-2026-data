
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a1;string a,b;long long c=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a1 >> b;
        for(int j=0;j<a1;j++){
            a += b;
        }
    }
    for(int i=0;i<a.size() / 2;i++){
        int l = a.size() - i-1;
        if(a[i] != a[l]) c++;
    }
    cout <<c;
    return 0;
}



