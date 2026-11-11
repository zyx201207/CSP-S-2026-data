#include<bits/stdc++.h>
using namespace std;

int n,cntans;
long long cnt;
int ni[200005];
char c[200005];
string a;
string b1;
string b2;


int main(){
	
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ni[i]>>c[i];
		for(int j=0;j<ni[i];j++){
			a+=c[i];
		}
	}
	//cout<<a;
	for(int i=0;i<(a.size()/2);i++){
		b1+=a[i];
	}
	for(int i=a.size()-1;i>(a.size()/2);i--){
		b2+=a[i];
	}
	//cout<<"debug "<<a<<" "<<b1<<" "<<b2;
	for(int i=0;i<a.size();i++){
		if(b1[i]!=b2[i]){
			cntans+=1;
		}
	}
	cout<<cntans;
	return 0;
}
