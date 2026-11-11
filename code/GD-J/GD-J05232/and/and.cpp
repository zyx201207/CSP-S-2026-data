#include<bits/stdc++.h> 
using namespace std;
int n,m,ans=0,cnt=0;
string a[200005];
string b[200005];
void iand(){
	for(int i=1;i<=n;i++){
		int op=0,ip=0; 
		for(int j=0;j<a[i].size();j++){
			op=op*10+a[i][j]-'0';
		}
		for(int j=i+1;j<=n;j++){
			ip=0;
			for(int k=0;k<a[j].size();k++){
				ip=ip*10+a[j][k]-'0';
			}
			ans=max(ans,op&ip);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	iand();
	cout<<ans;
	return 0;
}

