#include<bits/stdc++.h>
using namespace std;
int n,m,num[200005],ans=0;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1,cmp);
	ans=num[1];
	for(int i=2;i<=m;i++){
		ans=ans&num[i];
	}
	cout<<ans;
	return 0;
}

