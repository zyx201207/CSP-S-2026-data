#include <bits/stdc++.h>
using namespace std;
int n,m,a[100500],num;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]*i<=m){
            num=i;
        }
    }
    cout << num;
	return 0;
}
