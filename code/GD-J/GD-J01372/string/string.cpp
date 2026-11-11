#include<bits/stdc++.h>
using namespace std;
long long n,y=99999999999;
string k;
int hw(string z){
	long long o=0;
	for(long long j=z.size()-1;j>=0;j--){
		if(z[o]!=z[j]){
			return 0;
		}
		o++;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long h=n,sum=0;
	while(h--){
		long long m;
		char a;
		cin>>m>>a;
		for(long long i=1;i<=m;i++){
			k+=a;
		}
		y=min(y,m);
	}
	int o2=0;
	if(n==1||hw(k)==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<y;
		return 0;
	}
	for(long long i=k.size()-1;i>=k.size()/2;i--){
		if(k[i]==k[o2]){
			o2++;
			continue;
		}
		sum++;
		k[i]=k[o2];
		o2++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
