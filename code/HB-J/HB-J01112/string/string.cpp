#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	while(n--){
		long long a;
		string c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i=1;i<s.size();i++){
			if(s[i]!=s[0]){
				m=i;
				break;
			}
	}
	long long sum=0;
	for(int i=m;i<s.size();i++){
			if(s[i]!=s[0]&&s[i]!=s[m]){
					sum++;
			}
	}
	cout<<sum;
	return 0;
}
