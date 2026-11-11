#include<bits/stdc++.h>
using namespace std;
string b;
int n;
int a[(int)1e7+5];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			b+=c;
		}
	}
	string d;
	for(int i=b.size()-1;i>=0;i--){
		d+=b[i];
	}
	if(b==d){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=0;i<b.size();i++){
		if(b[i]!=d[i]){
			cnt+=1;
		}
	}
	cout<<cnt/2;
	return 0;
}
