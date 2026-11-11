#include<bits/stdc++.h>
using namespace std;
string s;
char a[200005];
int num[200005],sum;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<num[i];j++){
			s+=a[i];
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]) sum++;
	}
	cout<<sum;
	return 0;
}
