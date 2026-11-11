#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200005];
	char c[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long len=s.size();
	if(s.size()%2==1){
		len+=1;
	}
	long long ans=0;
	for(int i=0;i<len;i++){
		if(a[i]==a[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
