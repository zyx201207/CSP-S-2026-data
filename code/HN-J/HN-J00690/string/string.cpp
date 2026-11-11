#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=0;j<a;j++){
			s.push_back(b);
		}
	}
	int x=s.size(),z=0;
	string qc,hc;
	qc=s.substr(0,x/2);
	if(x%2==0) hc=s.substr(x/2,x/2);
	else hc=s.substr(x/2+1,x/2);
	if(qc==hc){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<qc.size();i++){
		int f1=qc[i],f2=hc[i];
		if(f1==f2) z++;
	}
	cout<<qc.size()-z;
	return 0;
}
