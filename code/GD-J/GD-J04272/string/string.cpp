#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,sum=0;
	char c;
	cin>>n;
	if(n==1) cout<<0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int mid=(n+1)/2;
	for(int i=1;i<mid;i++){
		for(int j=mid;j<=n;j++){
			if(s[i]!=s[j]){
				s[j]=s[i];
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
