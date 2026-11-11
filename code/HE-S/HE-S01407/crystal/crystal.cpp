#include<bits/stdc++.h>

using namespace std;

const int ma=5e5+5;
long long n,m,mm,a[ma],ans,an;
bool v[ma];
long long f(int x,int h){
	mm=m;
	ans=0;
	for(int i=h;i>=1;i--){
		long long cnt=x-a[i];
		mm-=cnt;
		ans++;
		if(mm<0){
			ans--;
			return ans;
		}
		
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(n<=5000||m<=10000000){
		for(int i=n-1;i>=1;i--){
			if(a[i]!=a[i+1]){
				an=max(f(a[i],i),an);
			}
		}
		cout<<an;
		return 0;
	}
	mm=m;
	long long der=a[n]-a[n-1],sn=1;
	for(int i=n-1;i>=1;i--){
		mm-=der;
		sn++;
		if(mm<0){
			sn--;break;
		}
	}
	cout<<sn;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
int l=a[1]-1,r=a[n]+1;
int mid;
while(l<=r){
		mm=m;
		mid=(l+r)>>1;
		if(f(mid)==1){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
*/
