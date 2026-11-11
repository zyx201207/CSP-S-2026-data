#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	long long n,a;
	char c;
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long j=s.size()-1,x=0;
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[j]){
			x++;
		}
		j--; 
	} 
	cout<<x;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
