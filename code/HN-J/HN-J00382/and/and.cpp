#include<bits/stdc++.h>
using namespace std;
int n;int m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long max;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(max<a[i])max=a[i];
	}
	if(m==1)cout<<max;
	if(m==n)cout<<0;
	fclose(stdin);fclose(stdout);
	return 0;
}


