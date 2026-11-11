#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int l=0;
	for(int i=0;i<n;i++){
		if(m==0){
			break;
		}
		if(a[l]!=a[i]){
			m--;
			if(a[l]>a[i]){
				a[i]++;
			}else{
				a[l]++;
			}
			i=0;
		}
	}
	for(int i=0;i<n;i++){
		if(a[l]==a[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
