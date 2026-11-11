#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	string s="";
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0"<<endl;
		return 0;
	}   			
		for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}		
		for(int j=0;j<s.size();j++){
			if(s[j]!=s[s.size()-j-1]){
				s[s.size()-j-1]=s[j];
				sum++;
			}			
		}	
	cout<<sum<<endl;			
	return 0;
}
