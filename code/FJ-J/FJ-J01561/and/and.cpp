#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(and.in,'r');
	freend(and.out,'w');
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int ans[m],ans2,ans3;
	for(int i=1;i<=m;i++){
		while(a[i]!=0){
			a[i]=a[i]&a[i]-1;
			ans[i]++;
		}
		ans2=max(ans2,ans[i]);
	}
	for(int i=1;i<=ans2;i++){
		ans3=ans3*2;
	}
	return 0;
}
