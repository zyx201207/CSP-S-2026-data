#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);  
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int s=0;s<t;s++){
		int n,m;
		cin>>n>>m;
		int a[n+1];
		for(int i=0;i<n;i++)cin>>a[i];
		int sum=0;
			int  d=a[1]-a[0];
			if(m<d){
				cout<<0<<'\n';
				continue;
			}
			for(int x=0;x<n-1;x++){//x
				for(int y=x+1;y<n;y++){
					int f=(y-x)*d;
					if(f%m==0||x+1==y)continue;
					sum++;
				}
			}
			cout<<sum<<'\n';
	}
	
	
	return 0;
}
