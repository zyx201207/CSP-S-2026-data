#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxc=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxc=max(maxc,a[i]);
	}
	if(m==1){
		cout<<maxc;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
