#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char str[1000000];
	int cnt=0;
	int cnt_cnt=0;
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		char b;
		cin>>b;
		for(int j=cnt;j<cnt+a;j++){
			str[j]=b;
		}
		cnt+=a;
	}
	for(int i=0;i<cnt/2;i++){
		if(str[i]!=str[cnt-i-1]) cnt_cnt++;
	}
	cout<<cnt_cnt;
	return 0;
}