#include<bits/stdc++.h>
using namespace std;
int n,m,x[500000],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int a=0;a<n;++a){
		cin>>x[a];
		sum+=x[a];
	}
	sort(x,x+n);
	int l=0;
	for(int a=0;a<m;){
		if(x[l]==x[l+1]&&l!=n-1){
			++l;
		}
		a+=l+1;
		x[l]++;
	}
	while(x[l]==x[l+1]){
		l++;
	}
	cout<<l+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
