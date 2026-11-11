#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,cnt;
char c[200001],s[200000000000001];
long long a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt+=a[i];
		char q;
		cin>>q;
		c[i]=q; 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[j];j++){
			s[j]=a[j];
		}
	}
	for(int i=0;i<cnt;i++){
		if(s[i]!=s[cnt-i-1]){
			sum++;
		}
	}
		cout<<cnt<<endl;
	cout<<sum/2+1;
	return 0;
}
