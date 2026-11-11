#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,sum=0;
	cin>>n;
	string s;
	char c;
	for(int i=0;i<n;i++){
		cin>>m>>c;
		for(int j=0;j<m;j++){
			s+=c;
		}
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			sum++;
			s[j]=s[i];
		}
	}
	cout<<sum;
	return 0;
}
