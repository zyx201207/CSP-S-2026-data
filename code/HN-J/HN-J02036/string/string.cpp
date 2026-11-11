#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	long long a[200001],c = 0;
	char k;
	bool flag = false;
	scanf("%d",&n);
	for(int i = 0;i < n;++i){
		scanf("%lld",&a[i]);
		if(a[i] >= 1000000000){
			a[i] /= 1000000000;
			flag = true;
		}
		cin>>k;
		for(int j = 0;j < a[i];++j){
			s += k;
		}
	}
	for(int i = 0;i < s.size() / 2;++i){
		if(s[i] != s[s.size() - i - 1]){
			c++;
		}
	}
	if(flag){
		c *= 1000000000;
	}
	printf("%lld",c);
	return 0;
}
