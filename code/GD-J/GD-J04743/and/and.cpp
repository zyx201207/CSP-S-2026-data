#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int cnt=n-1;
	int maxa=a[cnt];
	cnt-=1;
	while(m-1>0){
		maxa&=a[cnt];
		cnt--;
		m--;	
	}
	cout<<maxa;
}

