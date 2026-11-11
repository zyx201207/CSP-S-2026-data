//GZ-J00139 遵义市第十一中学 雷朝典
#include<bits/stdc++.h>
using namespace std;
int main (){
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","o",stdout);
	long long n,n1,k=0;
	char s1;
	cin>>n;
	for(int y=0;y<n;y++){
		cin>>n1>>s1;
		for(int w=0;w<n1;w++){
			s=s+s1;
		}
	}
	cout<<s<<endl;
	n1=s.size();
	for(int y=0;y<n1/2;y++){
		if(s[y]!=s[n1-y-1]){
			k++;
		}
	}
	cout<<k;
} 
