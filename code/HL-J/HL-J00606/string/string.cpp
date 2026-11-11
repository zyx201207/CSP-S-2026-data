#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,e[200010],ans;
string aa[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n+1;i++){
		cin>>e[i]>>aa[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(e[1],e[2]);
		return 0;
	}
	int j=n;
	for(int i=1;i<(n+1)/2,j>=i;i++){
		if(aa[i]!=aa[j]){
			ans+=e[i];
		}
		j--;
	}
	cout<<ans;
	return 0;
}
