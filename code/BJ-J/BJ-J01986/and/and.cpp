#include<bits/stdc++.h>
using namespace std;
int n, max=0,m,mmax=0;
int main{
    ios::sync_with_stdio(flase);
    cin.tie();
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin >> n >> m;
    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        if(a>max){
            max = a;
        }
    }
    cout << max;
    return 0;
}