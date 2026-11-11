
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	vector<int> sz(n);
	for(int i=0;i<n;i++){
		cin>>sz[i];
	}
	
	sort(sz.begin(),sz.end());

	for(int i=0;i<n;i++){
		
		long long cs=m;

		long long ans2=0;
		for(int j=i;j>=0;j--){
			if(cs>=0){
				cs=cs-sz[i]+sz[j];
				ans2+=1;
			}
		}
		ans=max(ans,ans2);
	}
	cout<<ans;
	return 0;
}

//5 8
//-3 -1 2 2 7

//5 5
//1 2 4 8 9

//5 1000000000000000000
//10000 5000 0 -5000 -10000

