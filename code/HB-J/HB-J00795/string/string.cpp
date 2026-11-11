#include<bits/stdc++.h>
using namespace std;
string now;
long long ansz=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	long long len=0;
	long long a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		len+=a;
		for(int j=1;j<=a;j++){
			now+=c;
		}
	}
	int len1=len/2;
	for(int i=0;i<len1;i++){
		if(now[i]!=now[len-1-i]) ansz++;
	}
	cout<<ansz;
	return 0;
}
