#include<bits/stdc++.h>
using namespace std;
int n,a,l,r;
long long ans;
char c;
int s[200005];
char t[200005];
int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		s[i]=a,t[i]=c;
	}
	l=0,r=n-1;
	while(n&&l!=r){
		if(!s[r]){
			r--,n--;
		}
		if(!s[l]){
			l++,n--;
		}
		if(t[l]!=t[r]){
			ans+=min(s[l],s[r]);
		}
		s[l]-=min(s[l],s[r]),s[r]-=min(s[l],s[r]);
	}
	cout<<ans;
	return 0;
}
