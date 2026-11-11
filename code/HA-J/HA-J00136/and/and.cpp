#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> s(n);
	vector<bool> k(n,1);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(m==1){
		int a=-1;
		for(int i=0;i<n;i++){
			a=max(a,s[i]);
		}
		cout<<a;
		return 0;
	}else if(m==2){
		int a=-1;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				a=max(a,(s[i]&s[j]));
			}
		}
		cout<<a;
	}else if(m==n-1){
		int a,b=-1;
		vector<int> k();
		for(int i=0;i<n;i++){
			if(i==0){
				a=s[1];
			}else{
				a=s[0];
			}
			for(int j=0;j<n;j++){
				if(j!=i){
					a=(a&s[j]);
				}
			}
			b=max(a,b);
		}
		cout<<b;
	}else if(m==n){
		int a=(s[0]&s[1]);
		for(int i=2;i<n;i++){
			a=(a&s[i]);
		}
		cout<<a;
	}else{
	}
	return 0;
}
