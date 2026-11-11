#include<bits/stdc++.h>
using namespace std;
const int num = 2e5+5;
long long length_[num];
char c[num];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> length_[i] >> c[i];
	}
	long long i = 1;
	long long j = n;
	long long oti = length_[1];
	long long otj = length_[n];
	long long ans = 0;
	while(i<=j){
		long long min_ = min(oti,otj);
		if(c[i]!=c[j]){
			ans+=min_;
		}
		oti -= min_;
		otj -= min_;
		if(oti==0){
			i++;
			oti = length_[i];
		}
		if(otj==0){
			j--;
			otj = length_[j];
		}
	}
	cout << ans;
	return 0;
} 
