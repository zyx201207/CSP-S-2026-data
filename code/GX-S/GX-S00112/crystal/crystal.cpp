#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005],n,m,ans;

long long solve_plain(){//baoli
    int maxn = 0;
    for(int i = 0;i < n;i++){
        int sum = 0,pts = 0;
        for(int j = i;j >= 0;j--){
            sum += a[i] - a[j];
            if(sum <= m){
                pts++;
            }else{
                break;
            }
        }if(pts > maxn)maxn = pts;
    }return maxn;
}

long long solve_aii(){//a[i] = i
    int sum = 0,ret = 0;
    for(int i = 0;i <= n;i++){
        sum += i;
        if(sum <= m)ret++;
        else break;
    }return ret;
}long long solve_dc(long long gc){//dc
    int sum = 0,ret = 0;
    for(int i = 0;i <= n;i++){
        sum += i * gc;
        if(sum <= m)ret++;
        else break;
    }return ret;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool dc = true,aii = true;
    for(int i = 0;i < n;i++){
        scanf("%lld",&a[i]);
    }sort(a,a + n);
    int gc;
    for(int i = 2;i < n;i++){
        if(dc){
            if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
                dc = false;
            }if(a[i] - a[i - 1] != 1){
                aii = false;
            }
        }
    }
    if(n <= 12000){
        cout<<solve_plain();
    }else{
        if(dc){
            if(aii){
                cout<<solve_aii();
            }else{
                gc = a[1] - a[0];
                cout<<solve_dc(gc);
            }
        }else{
            cout<<solve_plain();
        }
    }
    return 0;
}
