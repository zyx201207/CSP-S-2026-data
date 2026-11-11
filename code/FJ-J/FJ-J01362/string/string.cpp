#include <bits/stdc++.h>
using namespace std;
int n;
string S;
int a[200005];
char c[200005];
bool need(int a,string b){
	for(int i=0;i<a;i++){
		if(b[i]!=b[a-1-i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=a[j];k++){
			S+=c[j];
		}
	}
	cout<<S;
	int a=S.length();
	if(need(a,S)){
		cout<<0;
		return 0; 
	}
	int ans=0;
	for(int l=0;l<a;l++){
		
		if(S[l]!=S[a-1-l]){
			S[a-1-l]=S[l];
			ans++;
		}
	} 
	cout<<ans;
	return 0;
}


