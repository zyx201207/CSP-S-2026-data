#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
unsigned long long a[N],m,pre[N];
int n,ans=-1;
int find(int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=l+r>>1;
		if(a[x]*(x-mid+1)-pre[x]+pre[mid-1]>m){
		l=mid+1;
	}
		else{
		r=mid;
		}
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>a[i];
	    sort(a+1,a+1+n); 
	    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
        for(int i=2;i<=n;i++)ans=max(ans,i-find(i)+1);
    printf("%d",ans);
	return 0;
}
/*
5 10
100 100 -200 -200 -300
*/
