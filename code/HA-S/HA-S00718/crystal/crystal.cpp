#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[1000001];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}else{
			while(m!=0){
				if(a[i]+1==a[i+1]){
					m--;
					ans++;
					break;
				}else{
					a[i]++;
					m--;
				}
				//break;
			}
		}
	}
	cout<<ans;
	return 0;
}
