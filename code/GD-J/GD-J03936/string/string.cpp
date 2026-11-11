#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
}R[2000005];
long long len,change;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>R[i].a>>R[i].c;
		len+=R[i].a;
	}
	for(int i=1;i<n;i++){
		if(R[i].c!=R[i+1].c){
			f=false;
			break;
		}
	}
	if(f||n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=R[i].a;j++){
			s+=R[i].c;
		}
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			change++;
		}
	}
	cout<<change;
	return 0;
}
