#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,a[1000000000005],b[1000000000005]={0},c[1000000000005]={0},ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	stor(a[i]+1,a[i]+n+1);
	for(int i=1;i<=n;i++ ){
		b[a[i]]++;
	}
	int t=max(b);
	int f=find(t)+1;
	ans+=t;
	int i=0;
	while(m!=0){
		i++
		m-=min(m/i,a[f-i]);
		ans+=min(m/i,a[f-i]);
		m-=min(m/i,a[f+i]);
		ans+=min(m/i,a[f+i]);
	}
	cout<<ans;
	
	return 0;
}
