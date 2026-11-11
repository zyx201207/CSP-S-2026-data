#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long w[500055];
long long i,j,k,p;
long long a[500055];
long long t[500055];
long long la;
long long sa[555];
long long ans;
long long dij[555][555];
//long long dij2[555][555];
long long sta[500055][22];
long long stt[500055][22];
bool dijflag[555][555];
long long x,y;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(i = 1;i <= m;i++){
        cin >> w[i];
    }
    for(i = 1;i <= n;i++){
        cin >> k;
        sa[i] = la + 1;
        for(j = 1;j <= k;j++){
            la++;
            cin >> a[la] >> t[la];
            sta[ a[la] ][0]++;
            sta[ a[la] ][ sta[a[la]][0] ] = i;
            stt[ a[la] ][ sta[a[la]][0] ] = t[la];
        }
    }

    for(i = 1;i <= 510;i++){
        for(j = 1;j <= 510;j++){
            dij[i][j]= 0x7FFFFFFFFFFFFFF;
            //dij2[i][j]= 0x7FFFFFFFFFFFFFF;
        }
        dij[i][i] = 0;
    }
    for(i = 1;i <= n;i++){//which line
        for(j = sa[i];j < sa[i + 1];j++){//which station
            for(p = 1;p <= sta[ a[j] ][0];p++){
                long long sideone = i;
                long long sidetwo = sta[ a[j] ][p];
                long long weight = t[j] + stt[ a[j] ][p];
                dij[sideone][sidetwo] = weight;
                dij[sidetwo][sideone] = weight;
            }
        }
    }
    for(i = 1;i <= n;i++){
        long long shortest = 100000;
        long long shortestnum = 0x7FFFFFFFFFFFFFF;
        dijflag[i][i] = 1;
        for(j = i;1;j = shortest){
            if(shortest == 100000){
                break;
            }
            shortest = 100000;
            shortestnum = 0x7FFFFFFFFFFFFFF;
            dijflag[i][j] = 1;
            for(p = 1;p <= n;p++){
                if(p == j)continue;
                if(dij[i][j] + dij[j][p] < dij[i][p]){
                    dij[i][p] = dij[i][j] + dij[j][p];
                }
                if(dijflag[i][p] == 0 && dij[i][j] + dij[i][p] < shortestnum){
                    shortest = p;
                    shortestnum = dij[i][j] + dij[j][p];
                }
            }
            //dij[i][q] = dij[i][j] + dij[j][p];
        }
    }
    for(i = 1;i <= q;i++){
        ans = 0x7FFFFFFFFFFFFFF;
        cin >> x >> y;
        for(j = 1;j <= sta[x][0];j++){
            for(p = 1;p <= sta[y][0];p++){
                long long sideone = sta[x][j];
                long long sidetwo = sta[y][p];
                long long between = dij[sta[x][j]][sta[y][p]];

                ans = min(ans,stt[x][j] +dij[sta[x][j]][sta[y][p]]+ stt[y][p]);
            }
        }
        ans += w[x] + w[y];
        cout << ans << endl;
    }
    return 0;
}
