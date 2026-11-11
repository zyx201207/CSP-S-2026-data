#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	int n,m,a[200005],ans,p;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ans=a[0]&a[1];
	for(int i=1;i<=n-1;i++){
		for(int j=2;j<=n;j++){
			p=a[j]&a[i];
			if(p>=ans)ans=p;}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}