#include<bits/stdc++.h>
#define F(i,a,b) for(int i = (a);i <= (b);i++)
#define D(i,a,b) for(int i = (a);i >= (b);i--)
using namespace std;
const int N = 100000000;
int n;
struct node{
    int a,next,ba;
    char c;
}a[N];
long long sum = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    F(i,1,n){
        cin>>a[i].a>>a[i].c;
        a[i].next = i + 1;
        a[i].ba = i - 1;
        sum += a[i].a;
    }
    sum /= 2;
    if(n == 1 || n == 0){
        cout << 0 << endl;
        return 0;
    }
    int nowp = 1,nowb = n,cnt = n,ans = 0;
    for(int i = 1;i <= sum;){
        if(a[nowp].a>a[nowb].a){
            a[++cnt].a = a[nowp].a - a[nowb].a;
            a[cnt].c = a[nowp].c;
            a[a[nowp].next].ba = cnt;
            a[cnt].next = a[nowp].next;
            a[cnt].ba = nowp;
            a[nowp].next = cnt;
            a[nowp].a = a[nowb].a;
        }else if(a[nowp].a<a[nowb].a){
            a[++cnt].a = a[nowb].a - a[nowp].a;
            a[cnt].c = a[nowb].c;
            a[a[nowb].ba].next = cnt;
            a[cnt].ba = a[nowb].ba;
            a[cnt].next = nowb;
            a[nowb].ba = cnt;
            a[nowb].a = a[nowp].a;
        }
        if(a[nowp].c!=a[nowb].c){
            ans += a[nowp].a;
        }
        i += a[nowb].a;
        nowp = a[nowp].next;
        nowb = a[nowb].ba;
    }
    cout<<ans<<endl;
    return 0;
}
