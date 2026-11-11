#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool A=true,B=true;
int n2(int n){
	int r=2;
	for(int i=2;i<=n;i++){
		r*=2;
	}
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,ai;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ai;
		a.push_back(ai);
		if(ai!=i&&B)B=false;
	}
	sort(a.begin(),a.end(),greater<int>());
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(m==n){
		int res=a[0];
		for(int i=1;i<n;i++){
			res=res&a[i];
		}
		cout<<res;
		return 0;
	}
	if(m==2){
		int res=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int resnow=a[i]&a[j];
				res=max(res,resnow);
			}
		}
		cout<<res;
		return 0;
	}
	if(m==n-1){
		a.erase(a.end()-1);
		int res=a[0];
		for(int i=1;i<n-1;i++){
			res=res&a[i];
		}
		cout<<res;
		return 0;
	}
	if(B){
		if(m>n/2){
			cout<<0;
			return 0;
		}else{
			cout<<n2(n)/2;
			return 0;
		}
	}
	return 0;
}
