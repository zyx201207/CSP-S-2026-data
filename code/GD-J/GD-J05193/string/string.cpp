#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	string s;
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		} 
	}
	long long h=0,l=s.size();
	long long i=(l-1)/2,j=(l+1)/2;
	while(i>=0&&j<l){
		if(s[i]!=s[j])h++;
		i--;
		j++;
	} 
	cout<<h;
	return 0;
}
