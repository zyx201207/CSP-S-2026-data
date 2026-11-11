//GZ-J00146 北师大贵阳附中 赵泊宁 
#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
char a;
string b,c,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>a;
		for(long long j=1;j<=m;j++){
			b+=a;
		}
	}
	for(long long i=1;i<=b.size()/2;i++){
		c+=b[i];
	}
	if(b.size()%2==0){
		for(long long i=b.size();i>b.size()/2;i--){
			d+=b[i];
		}
	}
	if(b.size()%2!=0){
		for(long long i=b.size();i>b.size()/2+1;i--){
			d+=b[i];
		}
	}
	for(long long i=1;i<=d.size();i++){
		if(c[i]!=d[i]){
			cnt++;
		}
	}
	if(cnt!=0){
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
