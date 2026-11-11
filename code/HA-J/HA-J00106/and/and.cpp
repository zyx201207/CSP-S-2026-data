#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n,m,a[200005]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	int na=1,num=0,posi=n;
	while(na<a[n]){
		na*=2;	
	}
	while(1){
		posi=n;
		num=0;
		for(;posi>=1;posi--){
			if(a[posi]<na&&a[posi]>=na/2)num++;
			else break;
		}
		if(num<m){
			for(int i=posi;i<=n;i++)a[i]=(a[i]&(na/2-1));
			sort(a+1,a+n+1);
			na/=2;
		}
		else {
			int ans=a[n];
			for(int i=n-1;i>=n-m+1;i--)ans=ans&a[i];
			cout<<ans;
			break;
		}
	}
	
		
	return 0;
}

