#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    string b;
    int c;
    int n;
    int le;
    int ans;
    cin >> n;
    for(int i = 1;i<= n;i++){
        cin >> c >> b;
        for(int i = 1;i <= c;i++){
			a += b;
		}
    }
    le = a.size()/2;
    for(int j= 1;j<= le;j++){
        if(a[j] != a[j+le]){
            ans += 1;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
