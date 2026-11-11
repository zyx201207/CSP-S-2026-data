#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500500],ans=1;
vector<long long>l;
void ddd(int st){
	long long k=m,cnt=1;
	for(int i=st-1;i>=0;i--){
		k-=(a[st]-a[i]);
		l.push_back(i);
		if(k<=0){
			if(k==0)cnt++; 
			ans=max(ans,cnt);
			return;
		}
		cnt++;
	}
	
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		ddd(i);
	}
	cout<<ans;
	return 0; 
} 
