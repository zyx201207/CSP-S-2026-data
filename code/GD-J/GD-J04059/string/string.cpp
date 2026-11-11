#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ai[200005]={0};
	char ci[200005]={};
	long long m=0;
	string str=" ";
	for(int i=1;i<=n;i++){
		cin>>ai[i]>>ci[i];
		m+=ai[i];
		for(int j=1;j<=ai[i];j++){
			str+=ci[i];
		}
	}
	long long ans=0;
	for(int i=1;i<=m/2;i++){
		if(str[i]!=str[m-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
