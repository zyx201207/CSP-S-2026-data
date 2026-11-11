#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long num[200010]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=2;i<=n;i++){
		while(100){
			if(num[i]>num[i-1]){
				long long x=num[i-1];
				num[i-1]=num[i];
				num[i]=x;
			}
		}
	}
	int ans=num[1];
	for(int i=2;i<=m;i++){
		ans=ans^num[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
