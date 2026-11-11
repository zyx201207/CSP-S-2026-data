#include<bits/stdc++.h>
using namespace std;
#define rep(_,st,ed) for(int _=st;_<=ed;_++)
int n,m;
#define ll long long
const int N=5e5+5;
ll a[N],qz[N];
int ans;
bool check(int mid,int i){
	if(a[i]*(i-mid)-(qz[i-1]-qz[mid-1])>m) return 0;
	return 1;
}
void checkfile(){
	if(system("fc crystal.out crystal4.ans")) cout<<"WA";
	else cout<<"AC";
} 
int main(){
	//checkfile();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) qz[i]=qz[i-1]+a[i];
	rep(i,2,n){
		int l=1,r=i-1,pos=r;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid-1,pos=mid;
			else l=mid+1;
		}
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
} 

