#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	string s,s1,s2;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	int size=s.size();
	s1=s.substr(0,size/2);
	if(size%2==0){
		s2=s.substr(size/2,size/2);
		reverse(s2.begin(),s2.end());
	}
	else{
		s2=s.substr(size/2+1,size/2);
		reverse(s2.begin(),s2.end());
	}
	long long count=0;
	for(int i=0;i<size/2;i++){
		if(s1[i]!=s2[i]) count++;
	}
	cout<<count;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
