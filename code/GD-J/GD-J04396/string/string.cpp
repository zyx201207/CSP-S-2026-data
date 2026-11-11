#include<bits/stdc++.h>
using namespace std;
int n,cnt;long long sum;
string b="";
long long a;char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++) b+=c;
	}
	//cout<<b;
	for(int i=1;i<=sum;i++){
		if(b[i]==b[sum+1-i]) cnt++;
	}
	//cout<<cnt;
	int f=0;
	if(sum&1){
		if(cnt*2-1==sum) f=1;
	}
	else{ 
		if(cnt*2==sum) f=1;
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	if(sum&1){
		cout<<(sum-1)/2;
	}
	else cout<<sum/2;
	return 0;
}
//aabbc

