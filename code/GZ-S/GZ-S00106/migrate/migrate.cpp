//GZ-S00106 个人报名 赵浩然 
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c,t;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cnt1=0;
		for(int j=1;j<=n-d;j++){
			for(int l=j+d;l<=n;l++){
				long long cnt=0;
				long long x=a[l]-a[j];
				for(int i=1;i<=d;i++){
					if(x-i<=d&&x-i>0&&x>d) cnt++;
					
				}
				if(cnt==2) cnt1++;
			}
		}
		
		cout<<cnt1<<endl;
	}
	
	
	return 0;
}
