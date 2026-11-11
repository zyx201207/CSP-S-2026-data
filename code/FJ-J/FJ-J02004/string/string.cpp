#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string str="x";
	for(int i=1;i<=n;i++){
		int a;
		char mnc;
		cin>>a>>mnc;
		for(int j=1;j<=a;j++){
			str+=mnc;
		}
	}
	long long len=str.size()-1,ans=0;
	for(int i=1;i<=len/2;i++){
		if(str[i]!=str[len-i+1])ans++;
	}
	cout<<ans;
	return 0;
}

