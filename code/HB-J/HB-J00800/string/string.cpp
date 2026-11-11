#include<bits/stdc++.h>
using namespace std;
char s[1000000000];
int cnt=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[cnt]=c;
			cnt++;
		}
	}
	long long sum=0;
	int len=cnt-1;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i]) sum++;
	}
	cout<<sum;
	return 0;
}
