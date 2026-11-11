#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long int n,a[100001]={},L=0;
	long long int aq[100001]={};
	double ans=0;
	char c[200001];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(long long int i=0;i<=(L/2);i++){
		if(s[i]!=s[L-i-1]){
			cout<<"s["<<i<<"]:"<<s[i]<<"  s["<<L-i-1<<"]:"<<s[L-i-1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
