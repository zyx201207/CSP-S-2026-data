#include<bits/stdc++.h>
using namespace std;
int h(string s){
	int l=s.size();
	long long sum=0;
	for(int i=0;i<l/2;i++){
		for(int j=l-1;j>=l/2;j--){
			if(s[i]!=s[j])
			sum++;
		}
	}
	return sum;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long a[200005];
	char c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		s+=c;
		}
	cout<<h(s);
	return 0;
}
