#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c,t; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long a[100005];
		int n;
		long long d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int cnt=0;
		if(d>=n-1){
			cout<<0<<endl;
			break;
		}
		for(int i=0;i<n;i++){
			for (int j=i+d+1;j<n;j++)
			if(a[i]-a[i]/d*d==a[j]%d) 
			cnt++;
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
