//GZ-S00246 贵阳市观山湖区第一高级中学 王思凯 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+10]={0};
	bool f=1;
	bool d=1;
	int b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=0;	
	}
	b=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=b) d=0;
	}
	if(f){
		int s=1;
		while(m>=0){
			m-=s;
			s++;
		}
		cout<<s-1;
		return 0;
	}
	cout<<m-1;
	return 0;
}
