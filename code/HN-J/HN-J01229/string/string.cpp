#include<bits/stdc++.h> 
using namespace std;
int n,a,sum;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int len=s.size()/2;
	for(int i=0;i<len;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
