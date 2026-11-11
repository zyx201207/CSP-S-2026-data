#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans;
struct zfc{
	long long a;
	char c;
};
zfc s1[300000],s0[300000];
int main (){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s1[i].a>>s1[i].c;
		s0[i].a=s1[i].a;
		s0[i].c=s1[i].c;
	}
	l=0;
	r=n-1;
	while(l<=r){
		if(s1[l].a>s0[r].a){
			if(s1[l].c!=s0[r].c){
				ans+=s0[r].a;
			}
			s1[l].a-=s0[r].a;
			r--; 
		}
		else if(s1[l].a<s0[r].a){
			if(s1[l].c!=s0[r].c){
				ans+=s1[l].a;
			}
			s0[r].a-=s1[l].a;
			l++; 
		}
		else if(s1[l].a==s0[r].a){
			if(s1[l].c!=s0[r].c){
				ans+=s0[r].a;
			}
			l++;
			r--; 
		}
	}
	cout<<ans;
	return 0;
}

