#include<bits/stdc++.h>
using namespace std;
long long cnt;
string s1,s2;
long long a;
char b;
int main(){
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>b;
		for(long long j=0;j<a;j++){
			s1+=b;
		}
	}
                s2=s1;
				reverse(s1.begin(),s1.end());	
if(s1==s2){
		cout<<0;
		return 0;
	}

	for(long long i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			s1[i]=s2[i];
			cnt++;
		}       s2=s1;
				reverse(s1.begin(),s1.end());
	
	}
	//Ô­×Ö·û´®-- s2
	//·´×ª×Ö·û´® --s1
	
	cout<<cnt;
	return 0;
	
	
	
	
}
