#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[100000000005],ans[100000000005],b=0,s=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n/2+1;i++)ans[i]=a[n/2+1]-a[i];
	for(int i=1;i<=n/2;i++){
		if(m<=b){
			b=ans[i-1]+ans[i];
			s++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
