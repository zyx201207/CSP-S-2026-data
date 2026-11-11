#include<iostream>
#include<stack>
#include<algorithm>
#define int long long
using namespace std;

const int MAXE = 30+5;
const int MAXN = signed(2e5)+5;

struct node{
    int num;
    int e1;// 二进制中1的数量
    int cnt;// 二进制位数量
    int e[MAXE];// 二进制
}a[MAXN];
int n,m;

node to_ejz(node _x){
    node x = _x;
    int num = x.num;
    stack <int> stt;
    while(!stt.empty()) stt.pop();
    while(num >= 2){
        stt.push(num%2);
        num /= 2;
    }
    stt.push(num);
    int cnt = 1;
    x.e1 = 0;
    while(!stt.empty()){
        int fr = stt.top();
        if(fr)  x.e1++;
        x.e[cnt++] = fr;
        stt.pop();
    }
    x.cnt = cnt-1;
    return x;
}

bool cmpxzA(node x,node y){
    return x.e1>y.e1;
}

int dfs_ans = 0;

void dfs(int step,int xz = 0,int val = 0){
    if(step == n+1){
        dfs_ans = max(dfs_ans,val);
        return ;
    }
    if(step == 1){
        dfs(step+1,xz+1,a[1].num);
        dfs(step+1,xz,0);
    }
    else{
        dfs(step+1,xz+1,(val&a[step].num));
        dfs(step+1,xz,val);
    }
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    // frepopen
    cin >> n >> m;
    bool flag = true;
    int maxn = -0x3f3f3f3f;
    for(int i = 1;i<=n;i++){
        cin >> a[i].num;
        a[i] = to_ejz(a[i]);
    }
    for(int i = 1;i<=n;i++){
        maxn = max(maxn,a[i].num);
        if(a[i].cnt != a[i].e1){
            flag = false;
        }
    }
    if(m == 1){
        cout << maxn << endl;
        exit(0);
    }
    else if(m == 2){
        maxn = -0x3f3f3f3f;
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                maxn = max(maxn,(a[i].num&a[j].num));
            }
        }
        cout << maxn << endl;
        exit(0);
    }
    else if(m == n){
        int maxn = a[1].num;
        for(int i = 2;i<=n;i++){
            maxn &= a[i].num;
        }
        cout << maxn << endl;
        exit(0);
    }
    else if(flag){
        sort(a+1,a+1+n,cmpxzA);
        cout << a[m].num << endl;
        exit(0);
    }
    else if(maxn == 3){
        int tong[9] = {0};
        for(int i = 1;i<=n;i++){
            tong[a[i].num]++;
        }
        if(tong[3] >= m){
            cout << 3 << endl;
        }
        else{
            if(tong[3]+tong[2] >= m){
                cout << 2 << endl;
            }
            else if(tong[3]+tong[2]+tong[1] >= m){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        exit(0);
    }
    else if(maxn == 2){
        int tong[9] = {0};
        for(int i = 1;i<=n;i++){
            tong[a[i].num]++;
        }
        if(tong[2] >= m){
            cout << 2 << endl;
        }
        else{
            if(tong[2]+tong[1] >= m){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        exit(0);
    }
    else if(maxn == 1){
        int tong[9] = {0};
        for(int i = 1;i<=n;i++){
            tong[a[i].num]++;
        }
        if(tong[1] >= m){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        exit(0);
    }
    else if(maxn == 0){
        cout << 0 << endl;
        exit(0);
    }
    else if(n <= 20){
        dfs(1);
        cout << dfs_ans << endl;
    }
    return 0;
}