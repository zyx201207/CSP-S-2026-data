#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}	
	string s;
	for(int i=1;i<=n;i++){
		long long m;
		char c;
		cin>>m>>c;
		for(int i=1;i<=m;i++){
			s+=c;	
		}	
	}
	long long ans=0;
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
