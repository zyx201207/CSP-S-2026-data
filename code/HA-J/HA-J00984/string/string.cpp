#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		sum+=a;
		char b;
		cin>>b;
		for(int j=sum-a;j<sum;j++){
			s[j]=b;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(s[i]!=s[sum-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
