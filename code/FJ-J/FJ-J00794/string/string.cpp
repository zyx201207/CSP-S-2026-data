#include<bits/stdc++.h>
using namespace std;
struct aw{
	long long z;
	char f;
} w[200100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i].z>>w[i].f;
		l+=w[i].z;
	}
	string e;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w[i].z;j++){
			e+=w[i].f;
		}
	}
	//cout<<l<<" ";
	//cout<<e;
	for(int i=0;i<=l/2-1;i++){
		if(e[i]!=e[l-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
