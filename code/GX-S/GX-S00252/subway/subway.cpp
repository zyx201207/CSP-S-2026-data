#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int times[1005];//walk time of every station
int plans[100005][5];// beginning and ending
int pt[1005][1005];// which path, how much time

int sum;

struct event{
    int s; // which station
    int t; // how much time
} es[1005][1005];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i=1;i<=m;i++){
        cin>>times[i];
    }

    int k[505];
    for(int i=1;i<=n;i++){
        cin >> k[i];
        for(int j=1;j<=k[i];j++){
            cin >> es[i][j].s;
            cin >> es[i][j].t;
        }
    }

    //for(int i=1;i<=n;i++){
      //  int k;
      //  cin >> k;
      //  for(int j=1;j<=k;j++){
      //      int num;
      //      cin >> num;
      //      cin >> pt[i][num];
     //   }
    //}

    for(int i=1;i<=q;i++){
        cin >> plans[i][1];
        cin >> plans[i][2];
    }

    for(int i=1;i<=q;i++){
        sum = times[plans[i][1]] + times[plans[i][2]];

        //come from which way
        event now;
        for(int j=1;j<=n;j++){
            if(es[j][1].s == plans[i][1]){
                now = es[j][2];
                break;
            }
        }

        event next = now;

        int n2 = n;
        while(n2--){
            for(int j=1;j<=n;j++){
                for(int l=1;l<k[i];l++){
                    event num = es[j][l];
                    if(num.t != next.t && num.s == next.s){
                        sum += num.t+next.t;
                        next = es[j][l+1];
                    }
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}
