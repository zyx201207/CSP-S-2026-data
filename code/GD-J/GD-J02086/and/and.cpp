#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
string s[N];
bool ans[N];
int num[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		int j=0;
		while(a[i]>0){
			s[i][j]=char(a[i]%2+'0');
			a[i]/=2;
			j++;
			num[i]++;
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<num[i];j++){
//			cout<<s[i][j];
//		}
//		cout<<endl;
//	}
//	
//	for(ll i=0;i<n;i++){
//		for(ll j=0;j<num[i];j++){
//			if(s[i][j]=='1'){
//				cout<<"一个";
//			}
//		}
//		cout<<endl;
//	}
	
	if(n==m){
//		ll num=0;
		ll max=-99;
		for(int i=0;i<n;i++){
			for(int j=0;j<=num[i];j++){
				if(s[i][j]=='1'){
					ans[j]=true;
				}
			}
			if(num[i]>max){
				max=num[i];
			}
		}
		int numm=0;
		for(ll i=0;i<max;i++){
//			cout<<ans[i];
			if(ans[i]==1){
//				cout<<"f";
				numm++;
			}
		}
		cout<<numm;
	}else if(m==1){
		ll max=-99;
		for(int i=0;i<n;i++){
			ll num_=0;
			for(int j=0;j<num[i];j++){
				if(s[i][j]-'0'){
					num_++;
				}
			}
			if(num_>max){
				max=num_;
			}
		}
		cout<<max;
	}else{
		//没辙了
		return 0; 
	}
	return 0;
}
