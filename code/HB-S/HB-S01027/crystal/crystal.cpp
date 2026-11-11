#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6+7;
priority_queue<int> que;
int a[MAXN],cha[MAXN];
int m = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,cnt,ans;
    cin>>n>>cnt;
    int p = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[++p];
        if(a[p]==a[p-1]){ans += 1;continue;}
    }
    sort(a+1,a+p+1);
    for(int j = 1;j<=p;j++){
        cha[j] = a[j]-a[j-1];
    }
    for(int now = 1;now<=n;now++){
        if(cnt>=0){
            m++;
            cnt -= cha[now]*m;
        }
    }
    cout << m+ans <<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
