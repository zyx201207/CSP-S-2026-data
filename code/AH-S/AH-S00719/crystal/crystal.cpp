#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1,0),diff(n+1,0);
	for(int i=0;i<n;i++){
		cin>>a[i+1];
		diff[i+1]=a[i+1]-a[i];
	}
	int ans=0;
	for(int i=0;i<m;i++){
		long long minn=9223372036854775807;
		int mini=0;
		for(int j=0;j<n;j++){
			if(abs(diff[j+1])<minn&&abs(diff[j+1])) minn=abs(diff[j+1]),mini=j+1;
		}
		if(diff[mini]>0) diff[mini]--,diff[mini+1]++;
		else diff[mini]++,diff[mini+1]--;
		if(count(diff.begin(),diff.end(),0)>=ans) ans=count(diff.begin(),diff.end(),0);
	}
	cout<<ans;
	return 0;
} 
