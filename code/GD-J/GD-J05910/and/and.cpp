#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx,cnt=1;
bool s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxx) maxx=a[i];
		s[a[i]]=1;
	}
	if(m==1) cout<<maxx;
	else{
		for(int i=maxx-1;i>=1;i--){
			if(s[i]) cnt++;
			if(cnt==m){
				cout<<i;
				return 0;
			} 
		}
	}
	return 0;
} 
