#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	while(n--){
		int x;
		string a;
		cin>>x;
		cin>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	int l;
	l=s.size();
	if(l%2==0){
		for(int i=1;i<=l/2;i++){
			if(s[l/2-i+1]!=s[l/2+i]) sum++;
		}
	}
	else{
		for(int i=1;i<=l/2;i++){
			if(s[l/2-i]!=s[l/2+i]) sum++;
		}	
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
