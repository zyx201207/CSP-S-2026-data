//GZ-S00302 郭雨晨 贵阳市第十八中学 
#include<bits/stdc++.h>
using namespace std;
int a[600000];
int c,n,m,d,q,s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		for(int i=1;i<=t;i++){
			int t1,t2;
			cin>>t1>>t2;
			s+=t1;
		}
	}
	for(int i=1;i<=q;i++){
		int t,t1;
		cin>>t>>t1;
		cout<<s+a[t]+a[t1]<<'\n';
	}
	
	return 0;
}

