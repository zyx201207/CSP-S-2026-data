#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string str;
	int n;
	cin>>n;
	long long len=0;
	for(int i=0;i<n;i++){
		int u;
		cin>>u;
		len+=u;
		char v;
		cin>>v;
		for(int i=0;i<u;i++)str+=v;
	}
	//cout<<str<<endl;
	long long ans=0;
	for(int i=0;i<len/2;i++){
		if(str[i]!=str[len-i-1])ans++;
	}
	cout<<ans;//CCFwoaini
	return 0;
}
