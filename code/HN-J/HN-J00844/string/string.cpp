#include<bits/stdc++.h>
using namespace std;
int n,z;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		char a;
		cin>>m>>a;
		for(int j=0;j<m;j++){
			s+=a;
		}
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			z++;
		}
		i++;
		j--;
	}
	cout<<z;
	return 0;
} 
