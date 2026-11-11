#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char s[100000000];
	int a[10000000];
	int n;
	int z=0;
	int m;
	char b[1001];
	int cnt=0;
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=a[i];
		cin>>b[i];
		for(int i=1;i<=m;i++){
			s[t]+=b[i];
			t++;
		}
		
	}
	for(int i=1,j=t-1;i<j;i++,j--){
		if(s[i]==s[j]){
			cnt++;
		}else{
			s[i]=s[j];
			z++;
		}
	}
	if(cnt==t-1){
		cout<<0;
	}
	cout<<z;
}

