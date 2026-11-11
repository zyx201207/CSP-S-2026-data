#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long maxn=0;
	for(int i=1;i<=n;i++){
		long long num=0,cnt=1;
		for(int j=1;j<=i-1;j++){
			num+=a[i]-a[j];
			if(num<=m){
				cnt++;
				maxn=max(maxn,cnt);
			}
			else{
				break;
			}
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
