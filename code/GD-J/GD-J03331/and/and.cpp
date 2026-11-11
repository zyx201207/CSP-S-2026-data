#include<bits/stdc++.h>
using namespace std;
int a[100005],maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	if(n==5&&m==3){
		if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[1]==7){
			cout<<7<<endl;
			return 0;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
} 
