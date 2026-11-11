#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000000010];
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int i=0;
	while(i<n){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
		i++;
	}
	int l=0,r=n;
	long long sum=0;
	while(l<=r){
		if(s[l]==s[r]){
			l++;
			r--;
		}
		else{
			s[r]=s[l];
			l++;
			r--;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
