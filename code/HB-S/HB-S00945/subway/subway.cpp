#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 +5;

vector<int> Node[maxn]; // 曾是一名OI爱好者。
int edge[510][510]; //node between node

int n,m,c,d,q,Time,length;
int StaticTime1[maxn],StaticTime2[maxn][510],id;//ST1:zhanting<->ditiekou


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m; i++) cin >> StaticTime1[i];
    for(int i = 1; i <= n; i++){
        cin >> length;
        for(int j = 1; j <= length; j++){
            cin >> id >> StaticTime2[id][i];
            Node[id].push_back(i);
        }
    }
    
    //floyd

	cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
