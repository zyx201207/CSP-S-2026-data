#include<bits/stdc++.h>
using namespace std;
string hwc;
long long gycn,gyca,ans;
char gycc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>gycn;
	while(gycn--){
		cin>>gyca>>gycc;
		while(gyca--){
			hwc+=gycc;
		}
	}
	for(int i=0;i<hwc.size();i++){
		if(hwc[i]!=hwc[hwc.size()-i-1]){
			hwc[i]=hwc[hwc.size()-i-1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
