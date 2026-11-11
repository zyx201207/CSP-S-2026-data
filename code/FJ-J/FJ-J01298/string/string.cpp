#include<bits/stdc++.h>
using namespace std;
string s;
int k=0;
int ans; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
			k++;
		}
	}
	string h1,h2;
	for(int i=0;i<=k/2;i++){
		h1+=s[i];
	}
	for(int i=k-1;i>=k/2;i--){
		h2+=s[i];
	}
	
	for(int i=0;i<=k/2;i++){
		if(h1[i]!=h2[i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
