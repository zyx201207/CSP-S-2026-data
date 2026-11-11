#include<bits/stdc++.h> 
using namespace std;
long long n=0,op=0,ans=0,k[200001];
string a,hui1,hui2;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i]>>b[i];
		op+=k[i];
	}
	if(k[0]>=1000000000){
		cout<<"2000000000";
		return 0;
	}
	long long sum=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=k[i];j++){
			sum++;
			if(sum<=(op/2)) hui1+=b[i];
			else if(sum>(op/2)) hui2+=b[i];
		}
	}
	long long su=hui1.size();
	for(long long i=0;i<hui2.size();i++){
		if(hui2[i]!=hui1[su]) ans++;
		su--;
	}
	cout<<(--ans);
	return 0;
}
