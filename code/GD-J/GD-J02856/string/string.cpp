#include<bits/stdc++.h>
using namespace std;
int n,a,sum,ch;
char c;
string cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) cnt+=c;
		sum+=a;
	}
	int sum1=sum;
	string vc=cnt;
	reverse(vc.begin(),vc.end());
	if(vc==cnt) cout<<0,exit(0);
	for(int i=0,j=sum-1;i<=sum1/2;i++,j--){
		if(cnt[i]!=cnt[j]){ch++;} 
		else continue;
	}
	cout<<ch;
	return 0;
}
