#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[10000]={},num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		sort(a+1,a+n+1);
		a[1]+=1;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]==a[1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
