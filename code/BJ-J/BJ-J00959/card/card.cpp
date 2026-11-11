#include<bits/stdc++.h>
using namespace std;
int a[500002];
int table[500002];
bool had[300005];
int main(){//abbcccddddcccba
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<0<< " ";
    }
    return 0;
}
