#include<bits/stdc++.h>
using namespace std;
int main(){
	//准考证号:GZ-J00249 姓名:王锴碹
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	vector<char> c;
	c.push_back(' ');
	for(int i = 1;i <= n;i++){
		long long a;
		scanf("%lld",a);
		char b;
		for(long long i = 1;i <= a;i++){
			c.push_back(b);
		}
	}
	long long cnt = 0;
	for(int i = 1;i < c.size();i++){
		if(c[i] != c[c.size() + 1 - i]) cnt++;
	}
	printf("%lld",cnt);
	return 0;
}
	 
