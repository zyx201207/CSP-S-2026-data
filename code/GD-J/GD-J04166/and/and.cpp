#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],s;
bool t=true;
int cyn(int i,int n,int s){
	int ma=-1;
	for(int j=i+1;j<=n;j++){
		ma=max(ma,s&cyn(j,n+1,s&a[j]));
	}
	return ma;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]&(a[i+1]))t=!t;
	}
	if(m==1){
		int ma=-1;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		s=ma;
	}
	else if(m==2){
		int ma=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		s=ma;
	}
	else if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
	}
	else if(t){
		sort(a+1,a+n+1);
		s=a[n-m+1];
	}
	else {
		s=cyn(1,n-m+1,214748347);
	}
	cout<<s;

	return 0;
}

