#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[10000005];
long long ans;
long long cry;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		a[i]++;
		m--;
		if(a[i]=a[i+1]){
			cry++;
		}
		if(m==0){
			break;
		}
	}
	cout<<cry;
	return 0;
}
