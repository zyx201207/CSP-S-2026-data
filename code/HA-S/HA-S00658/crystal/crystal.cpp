#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
deque<int>a;
bool teA=1;
bool teB=1;
unsigned long long deltam;
void caseA() {
	unsigned long long cry=1,m0,m1=0;
	while(m1<m) {
		m0=m1;
		cry+=1;
		m1+=cry;
		if(cry==n){
			cout<<n;
			return;
		}
		if(m0<m&&m<=m1) {
			cout<<cry;
			return ;
		}
	}
}
void caseB() {	
	if(m<deltam){
		cout<<"1";
		return ;
	}	
	unsigned long long cry=1,m0,m1=1;
	while(m1<m){
		m0=m1;
		cry+=1;
		m1=m1+cry*deltam;
		if(cry==n){
			cout<<n;
			return;
		}
		if(m0<m&&m<=m1){
			cout<<cry;
			return ;
		}
	}
}
bool cmp1(int t1,int t2){
	return t1>t2;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int t;
	for(int i=1; i<=n; i++) {
		cin>>t;
		a.push_back(t);
		if(t!=i) {
			teA=0;
		}
		if(i==2) {
			deltam=a[1]-a[0];
		} else if(i>2) {
			if(t-a[i-1-1]!=deltam) {
				teB=0;
			}
		}
	}		
	if(m==0) {
		cout<<1;
		return 0;
	}
	if(teA) {
		caseA();
		return 0;
	}
	if(teB) {
		caseB();
		return 0;
	}	
	int ans=1,ans2=1;
	sort(a.begin(),a.end(),cmp1);
	for(int i=0;i<n;i++){
		int cishu=m;
		int ruler=a[i];
		for(int j=1;j<n-i;j++){
			if(ruler-a[j]<=cishu){
				ans2+=1;								
				if(ans2==n){
					break;
				}				
				cishu=cishu-(ruler-a[j]);
				if(cishu==0){
					break;
				}
			}else{
				break;
			}
		}
		ans=max(ans,ans2);
		if(ans==n){
			break;
		}
		ans2=1;
	}
	cout<<ans;
	return 0;
}
