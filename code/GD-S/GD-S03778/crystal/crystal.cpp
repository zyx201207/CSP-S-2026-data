#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int MAXN=5e5+5;
ll a[MAXN],s[MAXN],n,m,d[MAXN];
bool check(int l,int r){
	ll s=0;
	for(int i=l;i<=r;i++){
		s+=a[r]-a[i];
		if(s>m)
			return false;
	}
	return true;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool A=true,B=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=false;
		d[i]=a[i]-a[i-1];
	}
	for(int i=3;i<=n;i++)
		if(d[i]!=d[i-1]){
			B=false;
			break;
		}
	sort(a+1,a+n+1);
	if(A||B){
		int cnt=0;
		for(int i=n;i>=1;i--){
			m-=a[n]-a[i];
			if(m>=0){
				cnt++;
			}
			else
				break;
		}
		cout<<cnt;
	}
	else{
		int ans=0;
		for(int r=1,l=1;r<=n;r++){
			while(!check(l,r)&&l<=r)
				l++;
			ans=max(ans,r-l+1);
		}
		cout<<ans;
	}
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
/*
5 8
3 1 2 2 7
*/
/*
5 1000
1 3 5 7 9
*/
