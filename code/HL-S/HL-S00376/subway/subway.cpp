#include <bits/stdc++.h>
using namespace std;
const int N = 505, K = 5e4+5;
int w[N], a[N][K], t[N][K], x, y;
vector<int> sub[K];
int main(){
freopen("subway.in", "r", stdin);
freopen("subway.out", "w", stdout);
int si=0, c, n, m, d, q, X;
cin >> c >> n >> m >> d >> q;

for(int i = 1;i <= m;i++)cin >> w[i];
for(int i = 1;i <= n;i++){
cin >> X;
for(int j = 1;j <= X;j++){
cin >> a[i][j] >> t[i][j];

sub[a[i][j]].push_back(i);
}}
for(int i = 1;i <= q;i++){
cin >> x >> y;
int ans = 0;
int flag = 0, ii = 0;
for(auto v : sub){
ii++;
if(sizeof(v) >= 2){flag==ii;break;}
}
if(sub[x][0]!=sub[y][0])ans = t[sub[ii][0]][ii] + t[sub[ii][1]][2];
cout << w[x] + w[y] + t[sub[x][0]][x] + t[sub[y][0]][y] +ans<< endl;
cout << t[sub[y][0]][x] << endl;
}

return 0;
}
