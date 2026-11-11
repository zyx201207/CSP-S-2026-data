#include<bits/stdc++.h>
#define re register
using namespace std;
const int N = 2e5 + 100;
int n,a[N],m;
bool cmp(int x,int y){
    return x > y;
}
int M(int x){
    if(x == 0) return 1;
    else if( x == 1) return 2;
    else if(x & 1) return M(x - 1) * 2;
    else return M(x / 2) * M(x / 2);
}
inline int YU(int x,int y){
    string Sx,Sy;
    while(x){
        Sx += x % 2 + '0';
        x /= 2;
    }
    while(y){
        Sy += y % 2 + '0';
        y /= 2;
    }
    int len = min(Sx.length(),Sy.length());
    string S;
    for(re int i = 0;i < len;i ++){
        if(Sx[i] == '1' && Sy[i] == '1'){
            S =  S + '1';
        }
        else S = S + '0';
    }
    long long ans = 0;
   // cout <<S << endl;
    for(re int i = 0,j = 0;i < len;i ++,j ++){
        ans += (S[i] - '0') * M(j);
    }
    return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(re int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1,cmp);
    long long  ans = a[1];

    for(re int i = 2;i <= m;i ++){
        ans = YU(ans,a[i]);
    }

    cout << ans;
	return 0;
}
