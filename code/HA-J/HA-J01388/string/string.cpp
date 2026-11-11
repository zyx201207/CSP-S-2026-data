#include<bits/stdc++.h>
using namespace std;
long long n,a[1000011],cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		string c;
		cin>>c;
		for(int j=0;j<a[i];j++)
			s+=c;
	}
	for(int i=0;i<ceil(s.size()/2);i++){
		if(s[i]==s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<ceil(s.size()/2)-cnt;
	return 0;
}
