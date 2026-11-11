//GZ-J00072 贵阳中天中学 李弈菓
#include<bits/stdc++.h> 
using namespace std;
int n,m,a[100005];
int minn;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			minn=min(a[i],a[j]);
		}
	}
	cout<<minn;
	return 0;
}
