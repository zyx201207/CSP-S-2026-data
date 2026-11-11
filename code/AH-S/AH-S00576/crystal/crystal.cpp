#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N],b[N],c[N];
long long n,m; 
int maxn=0;
bool check(int id){
	long long x=m;long long y=0;
	int s=0;
	for(int i=id; i<=n; i++){
		s=0;
		for(int j=i; j>=1; j--){
			if(y>x||s>=id){
			//	cout<<y<<" "<<s<<" ";
				return s>=id&&y<=x;
			}
			s++;
			y+=(a[i]-a[j]);
		//	if(id==4)
		//	cout<<y<<" "<<s<<" ";
		}
		if(y>x||s>=id)return s>=id&&y<=x;
	}
	return y<=x&&s>=id;
}
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1) ;
	b[n]=0;
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
//		cout<<l<<" "<<r<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
