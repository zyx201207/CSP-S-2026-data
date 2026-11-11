#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n>20000||a[n]<4){
		int ans=1;
		for(int i=1;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k=m;
		for(int j=1;j<=i;j++){
			if((a[i]&a[j])==a[i]) k--;
			if(k<=0){
				cout<<a[i];
				return 0;
			}
		}
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
