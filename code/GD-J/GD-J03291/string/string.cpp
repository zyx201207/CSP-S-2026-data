#include<bits\stdc++.h>
using namespace std;
int n;
long long ans;
string o;
int main(){
	ans = 0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0,cnt =0;i < n;i++){
		int t;
		char p;
		cin>>t>>p;
		for(int j = 1;j <= t;j++)
			o+=p;
	}
	//cout<<o;
	int asize =o.size();
	for(int i = 0;i < asize/2;i++){
		if(o[i] != o[asize-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
