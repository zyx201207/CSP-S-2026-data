#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long j = 0;
	for(int i = 0;i<n;i++){
		int b;
		char c;
		cin>>b>>c;
		for(int k = 0;k<b;k++){
			a+=c;
		}
		j+=b;
	}
	long long ans = 0;
	if(j%2 == 0){
		for(int i = 0;2*i<j;i++){
			if(a[i]!=a[j-i-1])ans++;
		}
	}else{
		for(int i = 0;2*i<j-1;i++){
			if(a[i]!=a[j-i-1])ans++;
		}
	}
	cout<<ans;
	return 0;
}
