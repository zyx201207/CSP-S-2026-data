#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[50005],b[50005],ans=1;
int main(){
	//freopen("crystal.in","r",stdin);
	///freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	//sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		cout<<b[i]<<' '<<m<<endl;
		if(m>b[i]) {
			ans++;
			m-=b[i];
		}
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
