#include<bits/stdc++.h>
using namespace std;
int n,d;
int sum(int x,int y){
	int p=0,o=0;
	while(p<x-y){
		p+=d;
		o++;
	}
	return o;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long a[2005], dp[2005],cnt;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		
		}
		d=d-d%(a[1]-a[0]);
		int s=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++){
				cnt=sum(a[i],a[j]);
				if(a[i]-a[j]<=cnt*d){
					dp[i]++;
				}
			}
			if(dp[i]==2){
				s++;
			} 
		} 
		cout<<s<<endl;	
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
