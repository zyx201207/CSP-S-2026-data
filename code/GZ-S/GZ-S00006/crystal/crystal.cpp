//GZ-S00006,裘滨溪,贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long MAX_=0,num_=0;
	bool fA=true,fB=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		MAX_=max(MAX_,abs(a[i]));
		if(fA && a[i]!=i){
			fA=false;
		}
		if(i==2){
			num_=a[i]-a[i-1];
		}
		if(fB && i>2 && a[i]-a[i-1]!=num_){
			fB=false;
		}
	}
	sort(a+1,a+n+1);
	if(MAX_<=100){
		vector<pair<long long,int> > A;
		long long num=a[1];
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(num==a[i]){
				cnt++;
			}else{
				A.push_back(make_pair(num,cnt));
				num=a[i];
				cnt=1;
			}
		}
		A.push_back(make_pair(num,cnt));
		int ans=0;
		for(int i=1;i<A.size();i++){
			int j=i-1,l=A[i].second;
			long long val=0;
			while(j>=0 && val+(A[i].first-A[j].first)*A[j].second<=m){
				val+=(A[i].first-A[j].first)*A[j].second;
				l+=A[j].second;
				j--;
			}
			long long d=m-val;
			l+=j<0?0:d/(A[i].first-A[j].first);
			ans=max(ans,l);
		}
		cout<<ans;
		return 0;
	}
	if(n<=5000){
		int ans=0;
		for(int i=2;i<=n;i++){
			int j=i-1;
			long long val=0;
			while(j>0 && val+a[i]-a[j]<=m){
				val+=a[i]-a[j];
				j--;
			}
			ans=max(ans,i-j);
		}
		cout<<ans;
		return 0;
	}
	if(fA){
		m*=2;
		long long ans=sqrt(1.0*m);
		while(ans*(ans+1LL)>m){
			ans--;
		}
		cout<<ans;
		return 0;
	}
	if(fB){
		m*=2;
		long long ans=sqrt(1.0*m/num_);
		while(1.0*ans*(ans+1LL)>1.0*m/num_){
			ans--;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
