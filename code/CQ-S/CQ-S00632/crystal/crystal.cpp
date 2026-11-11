#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n;
	long long m;
	long long ans=1;
	cin>>m;
	for(int i=1;n>=i;i++){
		cin>>a[i];
	}
	long long w=n/2+1;
	sort(a+1,a+n+1);
	
	int mid=a[w];
	while(m>0){
		m-=mid-a[w-1];
		if(m<0) break;
		ans++;
	}
	cout<<ans;
	return 0;
} 
