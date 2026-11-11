#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char a;
	string s;
	int m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int i=1;i<=m;i++){
			s+=a;
		}
	} 
	string s1=s;
	int l=s.size();
	for(int i=0;i<=l;i++)
	{
		s1[i]=s[l-i-1];
	}
	long long x=0;
	for(int i=0;i<l;i++){
 
		if(s1[i]==s[i]){
			break;
		}
		x++;
	}
	//cout<<s<<" "<<s1<<" ";
	cout<<x;
}
