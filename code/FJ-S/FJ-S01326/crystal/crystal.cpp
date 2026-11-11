#include<bits/stdc++.h>
using namespace std;//100
const int N=1e6+67;
int n,m,a[N],s[N];
bool check(int x){//点亮x个水晶 
	for(int p=x;p<=n;p++){//以p为结尾的，相邻的x个水晶要点亮 
		int sum=s[p]-s[p-x];
		int ned=x*a[p]-sum;//需要的增加数量 
		if(ned>m){//不能完成 
			continue;
		}
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	
	int l=1,r=n;
	while(l<r){//二分 
		int mid=(l+r)/2+1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;	
	return 0;
}
