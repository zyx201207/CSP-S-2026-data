#include<bits/stdc++.h>
using namespace std;
vector<int> n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,ans=0;
	string s;
	cin >>t;
	long long t1=t;
	while(t1--){
		long long a;
		string c;
		cin >>a>>c;
		s+=c;
		n.push_back(a);
	}
	long long i=0;
	while(t>i&&t-i!=1){
		if(s[i]==s[t-1]){
			if(n[i]<n[t-1]){
				n[t-1]-=n[i];
				i++;
			}else if(n[i]>n[t-1]){
			n[i]-=n[t-1];
			t--;
			}else{
				i++;
				t--;
			}
		}else{
			if(n[i]<n[t-1]){
				n[t-1]-=n[i];
				ans+=n[t-1];
				i++;
			}else if(n[i]>n[t-1]){
			n[i]-=n[t-1];
			ans+=n[i];
			t--;
			}else{
				ans+=n[i];
				i++;
				t--;
			}
		}
	}
	cout <<ans;
	return 0;
}
