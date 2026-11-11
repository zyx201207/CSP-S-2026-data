#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma,s;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	ma=0;
	if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=a[i]&a[j];
				ma=max(ma,s);
			} 
		}
		cout<<ma;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}
