#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];

string s;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	int l=s.size()/2;
	int i=0,j=s.size()-1;
	while(i<=l&&j>=l){
		if(s[i]!=s[j]){
			sum++;
		}
		i++,j--;
	}
	cout<<sum;
	return 0;
}
