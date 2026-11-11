#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[10000010];
string s,a1;
char m1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,m=0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		cin>>s[i];
		m+=a[i];
	}
	m1=s[1];
	
	for(int i=0; i<m; i++){
		for(int j=1; j<=a[i]; j++){
		a1[i]=s[i];
	}
}	
for(int i=0; i<m; i++){
		if(a1[i]!=m1){
		break;
		}cout<<0;
		return 0;
		
	}
	int l=1,r=m-1;
	for(int i=1; i<=m/2; i++){
		if(a1[l]!=a1[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

