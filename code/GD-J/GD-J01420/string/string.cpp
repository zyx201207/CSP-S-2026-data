#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long x[N];
char c[N];
string num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		num+=c[i];
	}
	int s=num.size();
	if(n==1){
		cout<<0;
	}
	else if(n!=1){
		int sum=0;
		for(int i=0;i<s;i++){
			sum+=num[i];
		}
		if((sum/s)==num[1]){
			cout<<0;
		}
	}
	return 0;
}
