#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int s,max=-1999;
		cin>>s;
		if(m>s){
			ans++;	
		}
	}
	cout<<ans;
	return 0;
}
