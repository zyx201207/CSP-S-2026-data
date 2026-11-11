#include<bits/stdc++.h>
using namespace std;
char b[100000005];
char d[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	long long cnt=0,ans=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		long long z;
		char c;
		cin>>z>>c;
		for(int j=1;j<=z;j++){
			cnt++;
			b[cnt]=c;
		}
	}
	for(int i=1;i<=cnt;i++){
		d[i]=b[cnt-i+1];
	}
	for(int i=1;i<=cnt/2+1;i++){
		if(b[i]!=d[i]){
			ans++;
			d[i]=b[i];
			b[cnt-i+1]=d[cnt-i+1];
		}
	}
	cout<<ans;
}
