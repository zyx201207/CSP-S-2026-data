#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+5;
char a[N];
int zm[26];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	long long js=0;
	for(int i=0;i<n;i++){
		int srs;
		cin>>srs;
		char srf;
		cin>>srf;
		for(int j=0;j<srs;j++){
			a[js]=srf;
			zm[srf-97]++;
			js++;
		}
	}
	for(int i=0;i<js;i++){
		if(zm[a[i]-97]>=zm[a[js-i-1]-97] && a[i]!=a[js-i-1]){
			a[js-i-1]=a[i];
			zm[a[i]-97]+=1;
			zm[a[js-i-1]-97]-=1;
			s++;
		}
		else if(zm[a[i]-97]<zm[a[js-i-1]-97] && a[i]!=a[js-i-1]){
			a[i]=a[js-i-1];
			zm[a[js-i-1]-97]+=1;
			zm[a[i]-97]-=1;
			s++;
		}
	}
	cout<<s;
	return 0;
}
