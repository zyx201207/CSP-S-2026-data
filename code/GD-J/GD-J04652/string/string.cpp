#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long sum=0;
long long cnt;
long long l[N];
string m="";

bool cmp(string m){
	string s=m;
	reverse(m.begin(),m.end());
	if(s==m) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		char a;
		cin>>a;
		if(a==' ') continue;
		sum+=l[i];
		m+=a;
	}
	if(cmp(m)){
		cout<<0;
		return 0;
	}
	cnt=sum/2;
	cout<<cnt;
	return 0;
}
