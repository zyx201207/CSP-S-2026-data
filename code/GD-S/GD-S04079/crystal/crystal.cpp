#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<int> ve(n);
	vector<long long> cnt(n);
	for(int i=0;i<n;i++){
		cin>>ve[i];
	}
	sort(ve.begin(),ve.end());
	cnt[0]=ve[0];
	for(int i=1;i<n;i++){
		cnt[i]=cnt[i-1]+ve[i];
	}
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=l+(r-l)/2;
		bool bo=0;
		for(int i=0;i+mid-1<n;i++){
			long long u=0;
			if(i)
			u=cnt[i+mid-1]-cnt[i-1];
			else 
			u=cnt[i+mid-1];
			long long v=ve[i+mid-1]*mid;
			long long ca=v-u;
			if(ca<=m){
				bo=1;
				break;
			}
		}
		if(bo){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
