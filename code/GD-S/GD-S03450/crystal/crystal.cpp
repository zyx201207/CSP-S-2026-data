#include<bits/stdc++.h>
using namespace std;
int n,m,ar[500005],t=-1e9,v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=1;j<=i;j++){
			s+=ar[i]-ar[j];
		}
		if(s<=m&&s>t){
			t=ar[i];
			v=i;
		}

	}
	cout<<v;
	return 0;
}
