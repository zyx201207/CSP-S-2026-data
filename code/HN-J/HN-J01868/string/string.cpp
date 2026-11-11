#include<bits/stdc++.h>
using namespace std;
int nm=0,m_=0;
long long n_,a_;
char b[200005];
string s_,c_;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n_;
	for(int i=0;i<n_;i++){
		cin>>a_>>b[i];
		for(int j=0;j<a_;j++){
			nm++;
			c_[nm]=b[i];
		}
	}
	for(int i=1;i<nm;i++){
		if(c_[i]!=c_[nm-1]) m_++;
	}
	cout<<m_;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}			
