#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n,m,max_=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;i++){
			max_=max(max_,a[i]&a[j]);
		}
	}
	cout<<max_;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

