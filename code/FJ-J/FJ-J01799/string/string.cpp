#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200000];
char c[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	cin>>n;
	if(n<=1){
		int x;
		char y;
		cin>>x>>y;
		cout<<"0";
		return 0;
	}
	int e=0;
	long long nm=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		nm+=a[i];
		if(i>=2&&c[i]!=c[i-1]){
			e++;
		}
	}
	if(e==0){
		cout<<"0";
		return 0;
	}
	vector<char> v;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			v.push_back(c[i]);
		}
	}
	int ij=1;
	for(int i=0;i<nm/2;i++){
		if(v[i]!=v[i+nm-ij]){
			ans++;
		}
		ij+=2;
	}
	cout<<ans;
	return 0;
}
