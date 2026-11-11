#include<bits/stdc++.h>
using namespace std;
string lst;
int a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0,ans=0;
	cin>>a;
	for(int i=1,b;i<=a;i++){
		char c;
		cin>>b>>c;
		for(int j=1;j<=b;j++) lst+=c;
		sum+=b;
	}
	for(int i=0;i<=sum/2-1;i++){
		if(lst[i]!=lst[sum-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
