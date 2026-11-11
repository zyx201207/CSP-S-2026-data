#include<bits/stdc++.h>
using namespace std;
long long a[200005]; 
string c[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];	
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	} 
	sum/=2;
	sum--;
	int ans=0;
	for(int i=0;i<=sum;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

