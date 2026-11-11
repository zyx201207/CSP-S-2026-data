#inclue<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int m[a];
    int n[b];
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i = 0;i <= a;i++){
        cin >> m[i];
        for(int j;j <= m.size();j++){
            for(int lxz = 0;lxz <= m.size;lxz++){
                n[lxz] = m[i];
                if(n.size() > m.size()){
                    cout << n[lxz];
                }
                else{
                    cout << m[i];
                }
            }
        }
    }
    return 0;
}
