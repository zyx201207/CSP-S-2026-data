#include<bits/stdc++.h>
using namespace std;
int main() { 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,a[200005],s=0,x=0;
	string s1;
	string c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
		for(int j=1;j<=a[i];j++){
			s1[j]=c[i];
		}
	}
	for(int i=1;i<=s/2;i++){
		if(s1[i]==s1[s-i+1]){
			x++;
		}
	}
	cout<<s/2-x;
	return 0;
}
