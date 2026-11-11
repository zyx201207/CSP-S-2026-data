#include <iostream>

using namespace std;

int main(){
    freopen("subway.in" ,"r" ,stdin);
    freopen("subway.out" ,"w" ,stdout);
    int c ,n ,m ,d ,q ,a ,k ,ans=0 ,fst ,lst;
    cin >> c >> n >> m >> d >> q;
    int w[500005];
    for(int i=1; i<=m; i++){
        cin >> w[i];
    }
    long long t[505][500005];
    for(int i=1; i<=n; i++){
        cin >> k;
        for(int j=1; j<=k; j++){
            cin >> a;
            cin >> t[i][a];
        }
    }
    for(int i=1; i<=r; i++){
        cin >> fst >> lst;
        ans+=w[fst]+w[lst];
        cout << ans << ednl;
    }
	return 0;
}
