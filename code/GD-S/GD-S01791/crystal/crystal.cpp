#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N+1];
int n;
bool specialAB(){
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cerr<<a[i]<<" ";
//	}
	int ans=1;
//	cerr<<endl<<specialAB();
	if(specialAB()){
		for(int i=1;i<=n;i++){
//			cerr<<endl<<((long long)i*((long long)i+1)/2)*(a[2]-a[1]);
			if(m>=((long long)i*((long long)i+1)/2)*(a[2]-a[1])){
				ans=max(ans,i+1);
			}
			else break;
		}
	}
	else{
		int lbound=1;
		for(int i=2;i<=n;i++){
	//			cerr<<endl<<lbound<<"-"<<i<<":"<<(i-lbound)*(a[i]-a[i-1]);
			while(m<(i-lbound)*(a[i]-a[i-1])){
				m+=a[i-1]-a[lbound];
				lbound++;
	//				cerr<<endl<<lbound<<"-"<<i<<":"<<(i-lbound)*(a[i]-a[i-1]);
			}
			if(m>=(i-lbound)*(a[i]-a[i-1])){
				m-=(i-lbound)*(a[i]-a[i-1]);
				ans=max(ans,i-lbound+1);
			}
			else{
				break;
			}
		}
	}
	cout<<ans;
//	cerr<<endl;
	cerr<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
