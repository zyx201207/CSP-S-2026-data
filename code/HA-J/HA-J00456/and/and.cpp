#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cam(int a,int b){
	return a>b; 
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);		
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll m,n;
	cin>>m>>n;
	
	
	vector<ll>lis(m);
	for(int i=0;i<m;i++){
		cin>>lis[i];
	}
	sort(lis.begin(),lis.end(),cam);
	 
	cout<<lis[n-1];
	return 0;
}
