#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,a[10005],sum=0;
	string s[10005],s1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s1+=s[i];
		}
	}
	for(int i=0,j=s1.size()-1;i<=j;i++,j--){
		if(s1[i]!=s1[j])sum++;
	}
	cout<<sum;
	return 0;
}
