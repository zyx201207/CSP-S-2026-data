#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,a[200005],sum;
string s1,s2;
char c[200005];  
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s1+=c[i];
		sum+=a[i];
	}
	long long len=s1.size();
	for(int i=len-1;i>=0;i--) s2+=s1[i];
	for(int i=0;i<sum;i++){
		if(s1[i]!=s2[i]) cnt++;
	}
	cnt/=2;
	cout<<cnt;
	return 0; 
} 
