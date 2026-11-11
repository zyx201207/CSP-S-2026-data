#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i,x[200005],j;
	char a[200005];
	string s;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x[i]>>a[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<min(x[1],x[2]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=x[i];j++){
			s=s+a[i];
		}
	}
	int ans;
	for(int w=0;w<s.size();i++){
		if(s[i]!=s[s.size()-i]){
			s[i]=s[s.size()-i];
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
