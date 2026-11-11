#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long a[N],c[N],s[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>v[n+10];
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i].push_back(0);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[i].push_back(abs(a[i]-a[j]));
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<j;i++){
			if(v[i][j]==0||i>=j)break;
			c[j]+=v[i][j];
		}
	}
	int id;
	for(int i=1,lmx=INT_MIN;i<=n;i++){
		if(c[i]>lmx&&c[i]<=m){
			lmx=c[i];
			id=i;
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){ 
		if(i>=id)break;
		a[i]+=v[i][id];
	}
	for(int i=1;i<=n;i++)s[a[i]]++;
	for(int i=1;i<=n;i++)ans=max(ans,s[a[i]]);
	cout<<ans<<endl;
	return 0;
}
