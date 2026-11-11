//GZ-J00649КывужабЇ ЭѕГЏюч 
#include<bits/stdc++.h> 
using namespace std;
long long n,a,l,sum;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++){
			s=s+c;
		}
	}
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1]){
			sum++;
		}
	}
	cout<<sum<<'\n';

	return 0;
}
