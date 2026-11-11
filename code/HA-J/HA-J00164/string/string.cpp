#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct chain{
	int num;
	char c;
};

vector <chain> s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	chain c0;
	for (int i=0;i<n;i++){
		cin >> c0.num >> c0.c;
		s.push_back(c0);
	}
	int lc=0,rc=n-1,li=0,ri=s[n-1].num-1;
	long long ans=0;
	while (lc<rc){
		int ans0 = min(s[lc].num-li,ri+1);
		if (s[lc].c!=s[rc].c) {
			ans+=ans0;
		}
		li+=ans0;
		ri-=ans0;
		if (li==s[lc].num){
			lc++;
			li=0;
		}
		if (ri==-1){
			rc--;
			ri=s[rc].num-1;
		}
	}
	cout << ans;
	return 0;
}
