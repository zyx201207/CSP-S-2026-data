#include <bits/stdc++.h>
using namespace std;
long long s[100010001000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int a=s[0];
	if(m==n){
		for(int i=1;i<n;i++){
			ans=(a&s[i]);	
		}
		cout<<ans;
	}else cout<<0;
	return 0;
}
