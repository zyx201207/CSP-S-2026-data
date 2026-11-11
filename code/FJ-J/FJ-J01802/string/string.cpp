#include <bits/stdc++.h> 
using namespace std;

string a,q;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	string b;
	cin>>n;
	bool p=0;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>m>>b;
		while(m--) a += b;
	}
	for(int i=0;i<a.size()-1;i++){
		if(a[i]==a[i+1]) p=1;
	}
	if(p=0) {
		cout<<0;
		return 0;
	}
	long long mid=a.size()/2;
	long long l=mid-1,r=mid+1;
	long long ans=0;
	while(l>0&&r<a.size()){
		if(a[l]!=a[r]) ans++;
		l--;
		r++;
	}	
	cout<<ans+1;
	return 0; 
}






