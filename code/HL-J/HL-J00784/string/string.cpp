#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ban,cssr,sum=0,whe=0;
	long long s[200000];
	char ccssr;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cssr;
		cin>>ccssr;
		for(int j=0;j<cssr;j++){
			s[whe] = ccssr-'0';
			whe++;
		}
	}
	ban = (whe)/2;
	for(int i=0;i<ban;i++){
		if(s[i]!=s[whe-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}