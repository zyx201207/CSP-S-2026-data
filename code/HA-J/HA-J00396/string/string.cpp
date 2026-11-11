#include<bits/stdc++.h>
using namespace std;
int rc,len,ans;
int xc;
string fz;
string rz,xz;
string s;
int n;
int c(string m){
	int cnt=0;
	for(int i=1;i<=len/2;i++){
		for(int j=len-1;j>=0;j--){
			fz +=m[i];
		}
		if(fz==m){
			return cnt;
		}	
		if(m[i]!=m[len-i]){
			cnt++;
			m[len-1]=m[i];
		}
		else{
			i++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		string b;
		cin>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	len=s.size();
	ans=c(s);
	cout << ans;
	return 0;
}
