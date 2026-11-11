#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005]={};
	char c[200005];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long sum=0;
	int i=0,j=s.size()-1;
	while(i<s.size()-1/2&&j>=(s.size()-1)/2+1){
		if(s[i]!=s[j])sum++;
		i++;
		j--;
	}
	cout<<sum;
	return 0;
}
