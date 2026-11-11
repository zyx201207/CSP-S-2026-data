#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//GZ-J00101 贵阳市南明区李端棻中学 曾俊豪
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int ans=a[0];
	for(int i=1;i<m;i++){
		int q=ans&a[i];
		if(q==0 || q<a[i]){
			m+=1;
			continue;
		}
		
		ans=q;
	}
	cout<<ans;
	return 0;
}
