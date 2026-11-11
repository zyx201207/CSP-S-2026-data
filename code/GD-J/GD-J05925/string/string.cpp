#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+7];
	char c[n+7];
	int q=0;
	char ww;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		if(c[i]!=c[0]) q=1;
		for(int j=0;j<a[i];j++){
			ww=ww+c[i];
		}
	}
	if(q==0) cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
