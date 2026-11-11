#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int cha[n];
	for(int i=1;i<n;i++){
		cha[i]=a[i]-a[i-1];
	}
	if(cha[1]==cha[2]){
		int qzh[n]={};
		int ans=0,num=1;
		for(int i=1;i<n;i++){
			qzh[i]=qzh[i-1]+cha[i];
		}
		int qzhq[n]={};
		for(int i=1;i<n;i++){
			qzhq[i]=qzhq[i-1]+qzh[i];
		}
		while(qzhq[num]<=m){
			num++;
			ans++;
		}
		cout<<ans;
	}else{
		int anss=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				int qzh[n]={};
				int ans=0,num=1;
				for(int z=1;z<n;z++){
					qzh[z]=qzh[z-1]+cha[z];
				}
				while(qzh[num]<=m){
					num++;
					ans++;
				}
				anss=max(ans,anss);
			}
		}
		cout<<anss;
	}	
	return 0;
}
