#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j,k=0,n,a;
	string s;
	char c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	//cout<<s<<endl;
	for(i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			k++;
		}
	}
	cout<<k;
	return 0;
} 
