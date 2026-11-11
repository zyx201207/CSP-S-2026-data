#include<bits/stdc++.h>
using namespace std;
string s[200005],c[200005];
int n;
long long a[200005],sum=0,t=0,num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		for(int j=1;j<=a[i];j++){
		s[t]=c[i];
		t++;
		}
	}
	
	for(int i=0;i*2<num;i++){
		cout<<s[i]<<s[num-i-1]<<endl;
		if(s[i]!=s[num-i-1]) sum++;
	}
	cout<<sum;
	return 0;
} 
