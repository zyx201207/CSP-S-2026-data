#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a,sum=0,num=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a>>c;
		num+=a;
	for(unsigned long long j=1;j<=a;j++) s+=c;
	}
	for(unsigned long long j=0,k=num-1;j<k;j++,k--){
		if(s[j]!=s[k]) sum++;
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
