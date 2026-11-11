#include<bits/stdc++.h>
using namespace std;
int n,m,c = 0;
int a[10000000];
int main(){
	freopen("crystal.in","r",stdin());
	freopen("crystal.out","w",stdout());
	cin >>n>>m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		if(a[i+1]-a[i]<m){
			a[i]++;
			m=m-(a[i+1]-a[i]);
			c+=1;
		}
		else{
			c+=3
			cout<<c;
		}
	}
	
	
	fclose(stdin());
	fclose(stdout());
	return 0;
}
