#include<bits/stdc++.h>
using namespace std;
int n,a;
string an="",v;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a>>v;
		for(int i=1;i<=a;i++) an+=v;
	}
	for(unsigned long long i=0;i<an.size()/2;i++){
		if(an[i]!=an[n-i]){
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
