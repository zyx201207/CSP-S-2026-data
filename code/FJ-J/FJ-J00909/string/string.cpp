#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	int m;
	string s;
	string a;
	for(int i=1;i<=n;i++){
		
		cin>>m>>s;
		for(int i=1;i<=m;i++){
			a+=s;
			
		}
		
		
		
	}
	long long cnt=0;
	
	
	for(int j=a.size()-1;j>=a.size()/2+1;j--){
		
		cnt++;
	}
	
	cout<<endl<<cnt;
	return 0;
}
