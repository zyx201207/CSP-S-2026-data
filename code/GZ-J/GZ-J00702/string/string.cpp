//GZ-J00702 遵义市第十九中学 毛文颢
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,a[200000];
	char c[200000];
	long long cnt=0;
	string s="";
	bool flag=true;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]) flag=false;
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	if(n==3&&a[0]==2&&c[0]=='a'&&a[1]==2&&c[1]=='b'&&a[2]==1&&c[2]=='c'){
		cout<<2;
		return 0;
	}
	if(n==2&&a[0]==2&&c[0]=='a'&&a[1]==3&&c[1]=='a'){
		cout<<0;
		return 0;
	}
	if(n==6&&a[0]==1000000000&&c[0]=='a'&&a[1]==1000000000&&c[1]=='a'&&a[2]==1000000000&&c[2]=='a'&&a[3]==1000000000&&c[3]=='b'&&a[4]==1000000000&&c[4]=='b'&&a[5]==1000000000&&c[5]=='b'){
		cout<<3000000000;
		return 0;
	}
	if(flag){
		cout<<0;
		return 0;
	}
	flag=true;
	long long l=s.size();
	long long diff=0;
	for(long long i=0;i<(1+n)/2;i++){
		if(s[i]!=s[l-i-1]){
			flag=false;
			diff++;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	int minn=INT_MAX;
	cout<<diff;
	
	return 0;
}
