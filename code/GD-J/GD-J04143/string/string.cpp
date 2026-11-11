#include <bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	long long o=n-1,x=0,i=0;
	while(i<o){
		if(a[i]==0){
			continue;
		}
		if(s[i]==s[o]){
			int mix=min(a[i],a[o]);
			a[i]-=mix;
			a[o]-=mix;
		}else{
			int mix=min(a[i],a[o]);
			a[i]-=mix;
			a[o]-=mix;
			x+=mix;
		}
		if(a[i]==0){
			i++;
		}
		if(a[o]==0){
			o--;
		}
	}
	cout<<x;
	return 0;
} 
