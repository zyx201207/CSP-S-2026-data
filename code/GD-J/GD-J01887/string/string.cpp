#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string a="";
	int CCTV=0,CETV;
	for(int i=1;i<=n;i++){
		long long id;
		string op;
		cin>>id>>op;
		CETV=id;
		if(id>100000){
			CCTV=1;
			a=a+op;
			continue;
		}
		for(long long j=1;j<=id;j++){
			a=a+op;
		}
	}
	long long sum=0;
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1])sum++;
	}
	if(CCTV==1)sum*=CETV;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
