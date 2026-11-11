#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	int n;	
	cin>>n;
	for(int i=1;i<=n;i++){
		long long s;
		cin>>s;
		char c;
		cin>>c;
		for(int j=1;j<=s;j++){
			s1+=c;
		} 
	}
	long long sum=0;
	for(int i=0;i<=s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
