#include<bits/stdc++.h>
using namespace std;
struct zi{
	int shu;
	string mu;
};
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	zi a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].shu>>a[i].mu;
	}
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].shu;j++){
			s+=a[i].mu;
		}
	}
	string m;
	for(int i=s.size()-1;i>=0;i--){
		m+=s[i];
	}
	if(m==s){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=m[i]){
			sum++;
		}
	}
	cout<<sum<<endl<<m<<endl<<s;
	return sum;
}
