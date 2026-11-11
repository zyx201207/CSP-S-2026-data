#include<bits/stdc++.h>
using namespace std;
int n;
int x[200005];
char c[200005];
string s;
long long sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		for(int j=1;j<=x[i];j++){
			s+=c[i];
		}
		sum+=x[i];
	}
	int l=0;
	int r=sum-1;
	while(l<=r){
		if(s[l]!=s[r])
			ans++;
		l++;
		r--;
	}
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
