#include<bits/stdc++.h>
using namespace std;
string s;
const int n_2=2*100000;
int a[n_2];
string x[n_2];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=a[i];
		}
	}bool f=0;
	int same=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]!=same) f=1;
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	int c=s.size();
	string s1;
	for(int i=1;i<=c/2;i++){
		s1[i]=s[i];
	}
	string s2;
	for(int i=c/2+2;i<=c;i++){
		s2[i]=s[i]; 
	}
	int count=0;
	for(int i=1;i<=n;i++){
		if(s2[i]!=s1[i]) count++;
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
