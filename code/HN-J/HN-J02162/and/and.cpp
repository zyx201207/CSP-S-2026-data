#include <bits/stdc++.h>
using namespace std;
int a[200005];
int t(int n,int m,int k){
	if (m!=2){
		cout<<1<<endl;
		int ans=0;
		for (int i=k;i<n;i++){
			int r=t(n,m-1,k+i+1);
			ans=max(ans,r&a[i]);
		}
		
		return ans;
	}
	else{
		int r=0;
		int i,j;
		for (i=k;i<n;i++){
			for (j=i+1;j<n;j++){
				r=max(r,a[j]&a[i]);
			}
		}
		return r;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans=0; 
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<t(n,m,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
