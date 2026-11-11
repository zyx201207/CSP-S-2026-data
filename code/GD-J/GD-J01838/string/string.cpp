#include<bits/stdc++.h>
using namespace std;

int n,cnt;
long long sum,ans;
struct node
{
    int a;
    char c;
}a[200005];
queue<node>q;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].a >> a[i].c;
        sum += a[i].a;
    }
    sum /= 2;
    for(int i = 1;i <= n;i++){
        if(sum > a[i].a){
            q.push(a[i]);
            sum -= a[i].a;
        }
        else {
            q.push({sum,a[i].c});
            break;
        }
    }
    int i = n;
    while(!q.empty()){
        node x = q.front();
        q.pop();
        while(x.a > 0){
            if(x.a > a[i].a){
                if(x.c != a[i].c)ans += a[i].a;
                x.a -= a[i].a;
                i--;
            }
            else {
                if(x.c != a[i].c)ans += x.a;
                a[i].a -= x.a;
                x.a = 0;
                if(a[i].a == 0)i--;
            }
        }
    }
    cout << ans;
}
