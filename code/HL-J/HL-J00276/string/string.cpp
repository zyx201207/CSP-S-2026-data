#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[2000990];
	long long n;
	long long key=1;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(long long  j=1;j<=x;j++){
			s[key]=c;
			key++;
		}
	}
	
	key--;
	long long cnt=0;
	for(long long i=1;i<=(int(key/2));i++){
		if(s[i]!=s[key+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
