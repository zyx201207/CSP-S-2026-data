#include<bits/stdc++.h>
using namespace std;
long long beg[200050]={}, len, n, x, cnt;
char ch[200050];
char find(long long pos){
	for(long long i = n; i >= 0; i--){
		if(pos >= beg[i]){
			return ch[i];
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 0; i < n; i++){
		cin>>beg[i+1]>>ch[i];
		len+=beg[i+1];
		beg[i+1]+=beg[i];
	}
	for(long long i = 0; i < len/2; i++){
		if(find(i) != find(len-i-1)) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
