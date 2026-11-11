//GZ-S00417 左成毅 黔南布依族苗族自治州都匀第一中学

#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long d[500010];
long long ans = 0;

bool cmp(int x,int y){
    return x < y;
}

long long max(int x,int y){
	if(x > y)return x;
	else return y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a,a + n,cmp);
    for(int i = 1;i <= n;i++){
        d[i] = a[i] - a[i - 1];
    }

    for(int i = 1;i < n;i++){
        long long cnt = 0;
        int j = i;
        int k = 1;
        while(cnt <= m && j < n){
            cnt = cnt + (d[j] * k);
            if(cnt > m)break;
            j++;
            ans = max(ans,k + 1);
            k++;
        }
    }
    cout<<ans;
    return 0;
}
