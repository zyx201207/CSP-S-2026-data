#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005],ea=0;
signed main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long min;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(min>a[i]) min=a[i];
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(a[i]==min){
				a[i]++;
				min++; 
			} //cout<<a[i]<<" ";
			if(min>a[i]){
				min=a[i];
			} 
			if(j==m-1){
				if(a[i]==min) ea++;
			}
		}	
	}	
	cout<<ea;
	return 0;
} 
