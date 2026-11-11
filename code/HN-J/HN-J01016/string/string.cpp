#include<bits/stdc++.h>
using namespace std;
int n;
string ans="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			ans+=c;
		}
	}
	int num=0;
	for(int i=0;i<ans.size()/2;i++){
		if(ans[i]!=ans[ans.size()-i-1]){
			num++;
		}
	}
	cout<<num;
	return 0;
} 
 
