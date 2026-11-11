#include<bits/stdc++.h>
using namespace std;
int a[10005];
string s1[10005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s1[i];
		for(int j=0;j<a[i];j++){
			s+=s1[i];
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]==s[l-1-i]){
			sum+=0;
		}else{
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
}

