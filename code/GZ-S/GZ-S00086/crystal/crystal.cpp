//GZ-S00086,刘炫希,贵州师范大学贵安新区附属初级中学
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll sum=0,m,ans=0;
vector <ll>a;
double mi=0;
bool cmp(ll x,ll y){
	return x<y;
}

bool cmp2(double x,double y){
	double a=abs(mi-x);
	double b=abs(mi-y);
	if (double(a)<double(b)){
		return x;
	}else{
		return y;
	}
}
double lwr_bd(double x){
	int l=0,r=n-1;
	while(l<r){
		int mid=(l+r)/2;
		if (a[mid]>=x){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return r;
}
int main(){
	freopen	("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		a.push_back(tmp);
		sum+=tmp; 
	}
	sort(a.begin(),a.end(),cmp);
	ll x=lwr_bd(5);
	double mi=(double(sum)+double(m))/double(n);
	sort(a.begin(),a.end(),cmp2);
	bool ok=0;
	ll haonan_6767=0;
	for (int i=0;i<n;i++){
		if (a[i]>mi){
			continue;
		}
		if (ok==0 && a[i]<=mi){
			haonan_6767=a[i];
			ok=1;
		}
		if (m<=0){
			break;
		}
		if (m>=(abs(haonan_6767-a[i]))){
			m-=haonan_6767-a[i];
			ans++;
		}
	}
	cout <<ans;
}
