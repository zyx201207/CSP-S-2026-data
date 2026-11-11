#include <bits/stdc++.h>
using namespace std;
int k[300002]={},ans[500002]={},n,m,a[500002];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		k[a[i]]++;
		//if(i>)
	}
	if(m==1) cout<<n;
	else{
		for(int i=1;i<=m;i++){
			cout<<k[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	
} 
