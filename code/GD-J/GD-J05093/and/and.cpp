#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200003],ans;
/*void bubble(){
	bool flag=0;
	while(1){
		for(int i=1;i<=n;i++){
			if(a[i]<a[i-1]) {
				swap(a[i],a[i-1]);
				flag=1;
			}
		}
		if(!flag) return;
	}
	return;
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	//bubble();
	ans=a[n];
	for(int i=1;i<m;i++){
		ans=ans&a[n-i];
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
