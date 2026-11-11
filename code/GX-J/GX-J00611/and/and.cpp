#inclue<bits/stdc++.h>
using namespace std;
int main(){
    int m[1024];
    int a,b,n;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> a >> b;
    for(int i = 1;i <= a;i++){
        cin >> m[i];
        for(int j = 0;j <= b;j++){
                if(m[j] and m[i] > m[j - 1] and m[i - 1]){
                    n == m[j] and m[i]}
    }
    }
    cout << n;
    return 0;
}
