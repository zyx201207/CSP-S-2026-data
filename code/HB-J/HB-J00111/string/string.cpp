#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	long long n,a;
	char c;
	string box;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			box+=c;
		}
	}
	long long l,r;
	l=0;
	r=box.size()-1;
	long long cnt=0;
	while(l<=r){
		if(box[l]!=box[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
