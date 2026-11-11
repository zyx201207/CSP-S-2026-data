#include<bits/stdc++.h>
using namespace std;
long long n[100010];
int main(){
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n[i];
	}
	int ans=-1000;
	for(int i=0;i<m;i++){
		int s=n[i]^n[i-1];
		if(s > ans){
			ans==s;
		}
	}
	cout<<ans;
	return 0;
}
