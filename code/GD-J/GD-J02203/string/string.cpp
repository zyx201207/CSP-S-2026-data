#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin>>n;
	string str="";
	for(int i=0;i<n;i++){
		long long a=0;
		char c=' ';
		cin>>a>>c;
		for(int j=0;j<a;j++){
			str+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<str.size()/2;i++){
		if(str[i]!=str[str.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
