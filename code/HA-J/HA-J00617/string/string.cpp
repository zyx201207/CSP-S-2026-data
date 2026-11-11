#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); 
	vector<char> a;
	int n;
	cin>>n;
	long long L=0;
	if(n==1){
		long long tmp;
		char c;
		cin>>tmp>>c;
		cout<<0;
		return 0;
	}
	
	
	for(int i=0;i<n;i++){
		long long tmp;
		char c;
		cin>>tmp>>c;
		L+=tmp;
		for(int i=0;i<tmp;i++) a.push_back(c);
	}
	
	long long f=L/2,le=L-1,cnt=0;
	for(int i=0;i<f;i++){
		if(a[i]!=a[i+le]){
			cnt++;
		}
		le-=2;
	}
	cout<<cnt;
	return 0;
}
