#include <bits/stdc++.h>
using namespace std;
const int R=1e5*5+5;
/*
9 6
1 2 3 4 12 13 14 15 15


*/
int n;
long long int arr[R],ans,m;
long long int check(int x){
    long long int k=0;
    int l=x;
    long long int cnt=0;
    while (k+(arr[x]-arr[l])<=m and l>=1){
        k+=arr[x]-arr[l];
        cnt++;
        l--;
    }
    return cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%lld",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    for (int i=2;i<=n;++i)
        ans=max(check(i),ans);
    printf("%lld",ans);
	return 0;
}

