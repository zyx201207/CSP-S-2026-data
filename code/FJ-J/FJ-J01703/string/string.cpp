#include<bits/stdc++.h>
using namespace std;
string ss="";
string ds="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			ss=ss+c;
		}
	}
//	cout<<ss<<" "<<ds<<endl;
	for(int i=ss.size()-1;i>=0;i--){
		ds=ds+ss[i];
	}
	int cnt=0;
	for(int i=0;i<ss.size();i++){
		if(ss[i]!=ds[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}

