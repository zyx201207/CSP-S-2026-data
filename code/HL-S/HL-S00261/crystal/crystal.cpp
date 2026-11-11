#include <bits/stdc++.h>
using namespace std;
/*
思路:均向一处归并,找到这个归并的最大值
并且归并的越大 所需m值也越多(单调性)
寻找最大值由于单调性可以使用二分

时间复杂度O(nlogn)
*/
using LL=long long;
const int N=5*1e5+5;
int a[N]; LL sum[N];
int n; LL m;

LL cost(int o,int k){
    return 1ll*a[k]*(k-o+1)-sum[k]+sum[o-1];
}
int f(int o){
    int l=o,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(cost(o,mid)<=m) l=mid;
        else r=mid-1;
    }
    return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);


	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
	}

	int res=0;
	for(int i=1;i<=n;i++){
        int k=f(i);
        while(a[k]==a[k+1]) k++;
        res=max(res,k-i+1);
	}
    cout<<res;
	return 0;
}
