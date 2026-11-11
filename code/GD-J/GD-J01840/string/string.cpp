#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int all;
	long long n,step;
	cin>>all;
	string high,now;
	for(int i=0;i<all;i++){
		cin>>n>>now;
		for(int j=0;j<n;j++) high+=now;
	}
	long long lenth=high.size();
	for(int i=0;i<(lenth/2);i++){
		if(high[i]!=high[lenth-i-1]) step++;
	}
	cout<<step;
    return 0;
} 
