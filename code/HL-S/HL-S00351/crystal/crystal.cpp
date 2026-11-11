#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,maxn = 0;cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(abs(a[i+2]-a[i])+abs(a[i+2]-a[i +1]) == m){
            a[i]+=a[i+2]-a[i];
            a[i+1] += a[i+2]-a[i+1];
        }
        else{
            i++;
        }
        //cout << a[i] << endl;
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == a[i+1]) cnt++;
        if(a[i] == a[i+2]) cnt++;
        if(a[i] == a[i+3]) cnt--;
    }
	cout << cnt;
    return 0;
}
