#include<iostream>
#include<algorithm>
using namespace std;
long long a[500001];
long long s[500001];
long long n,m;
int bs(int p){
	int l=0,r=p+1;
	long long piv=a[p];
	while(l<r){
		int mi=(l+r)/2;
		if((long long)(p-mi)*piv-(s[p]-s[mi])>m)l=mi+1;
		else r=mi;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1]; 
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i==n-1||a[i]<a[i+1]){
			ans=max(ans,i-bs(i));
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
