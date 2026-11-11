#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum;
string b[N],s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		int t=l-i;
		if(s[i]!=s[i+t-1]){
			sum++;
			s[i]=s[i+t-1];
		}
	}
	cout<<sum<<endl;
	return 0;
}
