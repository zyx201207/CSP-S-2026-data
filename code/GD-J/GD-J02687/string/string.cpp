#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<int>z(n);
	vector<char>chs(n);
	for(int i=0;i<n;i++){
		int m;
		char ch;
		cin>>m>>ch;
		z[i]=m;
		chs[i]=ch;
	}
	int alive=n,l=0,r=n-1,cnt=0;
	while(alive>1){
		int cntplus;
		if(z[l]==z[r]){
			cntplus=z[l];
			if(chs[l]!=chs[r])cnt+=cntplus;
			l++;
			r--;
			alive-=2;
		}
		else if(z[l]>z[r]){
			cntplus=z[r];
			z[l]-=z[r];
			if(chs[l]!=chs[r])cnt+=cntplus;
			r--;
			alive--;
		}
		else{
			cntplus=z[l];
			z[r]-=z[l];
			if(chs[l]!=chs[r])cnt+=cntplus;
			l++;
			alive--;
		}
	}
	cout<<cnt;
	return 0;
} 
