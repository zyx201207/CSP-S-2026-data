#include <bits/stdc++.h>

using namespace std;

int c,n,m,d,q;
int w[500005];
int t[505][500005],a[505][500005],k[505];

struct Node {
    vector<int> line;
    int w,t;
}st[500005];

struct Node2{
    int line,id;
};

int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) {
        cin >> w[i];
        st[i].w=w[i];
    }
    for(int i=1;i<=n;i++) {
        cin >> k[i];
        for(int j=1;j<=k[i];j++) {
            cin >> a[i][j] >> t[i][a[i][j]];
            st[a[i][j]].line.push_back(i);
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=q;i++) {
        int x,y;
        cin >> x >> y;
        //x's
        Node2 xx[500005]; int cnt1=0;
        for(int j=0;j<st[x].line.size();j++) {
            int tmp=st[x].line[j];
            for(int l=1;l<=k[tmp];l++)
                xx[++cnt1].id=a[tmp][l],xx[cnt1].line=tmp;
        }
        //y's
        Node2 yy[500005]; memset(yy,0,sizeof(yy)); int cnt2=0;
        for(int j=0;j<st[y].line.size();j++) {
            int tmp=st[y].line[j];
            for(int l=1;l<=k[tmp];l++)
                yy[++cnt2].id=a[tmp][l],yy[cnt2].line=tmp;
        }
        /*
        for(int j=1;j<=cnt1;j++) cout << xx[j].id << ' ';
        cout << endl;
        for(int j=1;j<=cnt2;j++) cout << yy[j].id << ' ';
        cout << endl << endl;
        */
        bool f=false;
        for(int a=1;a<=cnt1;a++) {
            for(int b=1;b<=cnt2;b++) {
                if(xx[a].id==yy[b].id) {
                    f=true;
                    ans=min(ans,t[xx[a].line][x]+t[xx[a].line][xx[a].id]+t[yy[b].line][yy[b].id]+t[yy[b].line][y]+w[x]+w[y]);
                    //int x=t[xx[a].line][xx[a].id]+t[yy[b].line][y]+t[yy[b].line][yy[b].id];
                    //cout << yy[b].line << ',' << y << ":" << t[yy[b].line][y] << endl << yy[b].line << ',' << yy[b].id << ":" << t[yy[b].line][yy[b].id]  << endl;

                }
                if(xx[a].id==y) {
                    f=true;
                    ans=min(ans,t[xx[a].line][x]+t[xx[a].line][y]+w[x]+w[y]);
                }
            }
        }

        /*
            int st,en;
            for(int a=1;a<=cnt1;a++) if(xx[a].id==x) st=a;
            for(int b=1;b<=cnt2;b++) if(yy[b].id==y) en=b;
            cout << xx[st].line << endl << yy[en].line << endl;
            for(int a=1;a<=cnt1;a++) {
                for(int b=1;b<=cnt2;b++) {
                   cout << xx[a].id << ' ' << xx[a].line << ' ' << yy[b].id << ' ' << yy[b].line <<  << endl;
                    //if(st[xx[a].id].line[1]==st[yy[b].id].line[1]) {
                        cout << x << endl;
                        cout << xx[st].line << ',' << x << endl;
                        cout << xx[st].line << ',' << xx[a].id << endl;
                        cout << xx[a].line << ',' << xx[a].id << endl;
                        cout << xx[a].line << ',' << yy[b].id << endl;
                        cout << yy[en].line << ',' << yy[b].id << endl;
                        cout << yy[en].line << ',' << yy[en].id << endl;
                        cout << y << endl;
                        ans=min(ans,w[x]+t[xx[st].line][x]+t[xx[st].line][xx[a].id]+t[xx[a].line][xx[a].id]+t[xx[a].line][yy[b].id]+t[xx[en].line][yy[b].id]+t[yy[en].line][yy[b].id]+w[y]);
                   // }
                }
            }
        */
        cout << ans << endl;
    }

    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
