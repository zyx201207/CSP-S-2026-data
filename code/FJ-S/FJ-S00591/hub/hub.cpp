#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int s[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int minn=-9999999;
	for(int i=1;i<=n;i++){
		if(s[i]<minn){
			s[i]=minn;
		}
	}
	cout<<minn;
	
	
	return 0;
}
