#include<bits/stdc++.h>
using namespace std;
long long n;
const int N=1e8+5;
typedef long long ll;
ll total;
int a[N];
char c[N];
char k[N];
string s;
ll cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool flag=1;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(ll i=0;i<n;i++){
		total+=a[i];
		
	}for(ll i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}for(ll i=0;i<total;i++){
		if(s[i]!=s[total-1-i]){
			flag=0;
			cnt++;
		}
	}if(flag==1){
		cout<<0;
	}else{
		cout<<cnt/2;
	}
	
	
	
	
	

	
	

	
	
	
	return 0;
}
