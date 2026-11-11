#include<bits/stdc++.h>
using namespace std;
long long n,m;
int s[100005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int o=0;
	for(int i=1;i<=n;i++){
			cin>>s[i];
			o=max(o,s[i]);
	}
	if(m==1){
		cout<<o;
	}
	return 0;
}


