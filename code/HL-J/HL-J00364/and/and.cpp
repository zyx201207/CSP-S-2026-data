#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(long long a,long long b){
	return a>b; 
}
int main(){
	long long n,m,s,maxj=0;
	freopen("and.in","r",stdin);
 	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}

	s=a[1];
	for(int i=2;i<=m;i++){
		s=s&a[i];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=maxj-1;j>=0;j--){
//			cout<<num[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<s;
	return 0;
}
