#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<char> a;
ll asz;
ll t;
bool check(){
	for(int i=0; i<=(asz-1)/2; i++){
		//cout<<a[i]<<" "<<a[asz-i-1]<<endl;
		if(a[i]!=a[asz-i-1])
			return false;//一开始不是回文
	}
	return true;
}
void g(){
	for(int i=0; i<=(asz-1)/2; i++){
		//cout<<a[i]<<" "<<a[asz-i-1]<<endl;
		if(a[i]!=a[asz-i-1])
			t++;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string5.in","r",stdin);
	freopen("string5.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		int s;
		char f;
		cin>>s>>f;
		asz+=s;
		while(s--)
			a.push_back(f);
	} 
	if(check()==true){
		cout<<0<<'\n';
		return 0;
	}
	else{
		g();
		cout<<t<<'\n';
	}
	return 0;
}
