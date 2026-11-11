#include <bits/stdc++.h>
using namespace std;
long long cmp(long long a,long long b){
	return a<=b;
}
long long crys(long long crystal[],int min,long long n,long long m){
	long long i=min,ans=1;
	while(i<n){
		if(i*(crystal[i]-crystal[i-1])<=m){
			m-=i*(crystal[i]-crystal[i-1]);
			ans++;
		}
		else if((i*(crystal[i]-crystal[i-1])-(crystal[min]-crystal[min-1]))<=m){
			m-=i*(crystal[i]-crystal[i-1])-(crystal[min]-crystal[min-1]);
			min++;
		}
		else{
			break;
		}
		i++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,ans;
	cin>>n>>m;
	long long crystal[n];
	memset(crystal,0,sizeof(crystal));
	for(int i=0;i<n;i++){
		cin>>crystal[i];
	}
	sort(crystal,crystal+n,cmp);
	ans=crys(crystal,1,n,m);
	for(int i=1;i<n;i++){
		if(crystal[i]-crystal[i-1]>m/2){
			ans=max(ans,crys(crystal,i,n,m));
		}
	}
	cout<<ans<<endl;
	return 0;
}
