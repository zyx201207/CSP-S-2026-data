#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+1;
int n;
ll m,a[maxn],sum[maxn];
int mx;
int check(int l,int r,int x){
//	cout<<(r-l+1)*x<<" "<<(sum[r]-sum[l-1])<<endl;
	return (r-l+1)*x-(sum[r]-sum[l-1]);
}
int Find(int i){
	int l=1,r=i;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid,i,a[i])<=m){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
	for(int i=1;i<=n;i++){
		mx=max(mx,i-Find(i)+1);
//		cout<<i<<" "<<Find(i)<<endl; 
	}
	cout<<mx<<endl;
    return 0;
}
/*
using ll=long long;
const int maxn=5e5+1;
int n;
ll m,a[maxn];
int mx;
int main(){
//    freopen("crystal.in","r",stdin);
//    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=a[i];
		int j=i-1;
		ll cost=m;
		int ans=1;
		while(j>=0){
			if(x-a[j]<=cost){
                ans++;
                cost-=x-a[j];
			}else{
                break;
			}
			j--;
		}
		mx=max(mx,ans);
//		if(i%10000==0) cout<<i<<endl; 
	}
	cout<<mx<<endl;
    return 0;
}
*/
