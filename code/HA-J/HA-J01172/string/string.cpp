#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string ans="",a="",b="";
	for(int i=0;i<n;i++){
		int x;
		char y;
		cin>>x>>y;
		while(x--){
			ans+=y;
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		a+=ans[i];
	}
	for(int i=0;i<n;i++){
		if(ans[i]!=a[i]){
			a[i]=ans[i];
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
