#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,g,gg,q;
vector<long long>a,b;
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>q;
		a.push_back(q);
	}
	sort(a.begin(),a.end());
	for(int i=n-1;i>=0;i--){
		if(a[i]==a[i+1])continue;
		for(int j=i-1;j>=0;j--){
			sum+=a[i]-a[j];
			if(sum>m)break;
			g++;
		}
		g++;
		gg=max(g,gg);
		g=sum=0;
	}
	cout<<gg;
	return 0;
}

