#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long m,a[maxn];
bool vis[maxn]={false};
int n;
priority_queue<pair<long long,int>>mn;
inline int tw(){
	int l=1,r;
	while(l<=n){
		if(a[l]+m<a[l+1])l++;
		else break;
	}
	r=l-1;
	while(!mn.empty())mn.pop();
	mn.push({LLONG_MIN,0});
	long long S=0,ma=0;
	while(r<=n){
//		cout<<l<<" "<<r<<" ";
		if(l==n)break;
		while(vis[mn.top().second]==true)mn.pop();
		while(r<n&&max((mn.top().first==LLONG_MIN?a[r+1]:mn.top().first),a[r+1])*(r-l+2)-S-a[r+1]<=m){
//			cout<<"---"<<max((mn.top().first==LLONG_MIN?a[r+1]:mn.top().first),a[r+1])*(r-l+2)-S-a[r+1]<<"---";
			r+=1;
			mn.push({a[r],r});
			ma=max(ma,(long long)r-l+1);
			S+=a[r];
			while(mn.top().first!=LLONG_MIN&&vis[mn.top().second])mn.pop();
		}
//		cout<<"---"<<S;//-a[r+1]<<"---";
//		cout<<l<<" "<<r<<'\n';
		if(l<r){
			vis[l]=true;
			S-=a[l];
			l++;
		}
		
	}
	return ma;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//É¾×¢ÊÍ
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=tw();
	cout<<ans<<'\n';
	return 0;
} 
/*
4 10
-91000 3 5 7

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/






//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=500005;
//long long m,a[maxn],pre[maxn]={0};
//int n;
//inline int ef(){
//	int l=1,r=n;
//	while(l<=n){
////		cout<<"-------\n";
//		if(a[l]+m<a[l+1])l++;
//		else break;
//	}
//	for(int i=l;i<=r;i++)pre[i]=pre[i-1]+a[i];
//	while(l<r){
//		int mid=l+r>>1;
////		cout<<l<<" "<<mid<<" "<<r<<'\n';
//		if(mid*a[mid]<=m+pre[mid])l=mid+1;
//		else r=mid;
//	}
//	return l-1;
//}
//int main(){
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//	freopen("crystal.in","r",stdin);
////	freopen("crystal.out","w",stdout);
////É¾×¢ÊÍ
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)cin>>a[i];
//	sort(a+1,a+n+1);
//	long long ans=ef();
//	cout<<ans<<'\n';
//	return 0;
//} 

