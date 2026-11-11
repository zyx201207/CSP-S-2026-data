#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int cnt;
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int k=1;
	for(int i=1;i<n;i++){
		if(k*(a[i+1]-a[i])<=m){
			m-=k*(a[i+1]-a[i]);
			if(f==0){
				f=1;
				cnt++;
			}
			cnt++;
			k++;
		}
	}
	cout<<cnt;
	return 0;
}
