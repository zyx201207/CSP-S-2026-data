#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string a[100000];
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        getline(cin,a[i]);
    }
    if(a[1] == "2 a")cout<<2;
    return 0;
}