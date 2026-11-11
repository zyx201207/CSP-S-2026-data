#include<bits/stdc++.h>
using namespace std;
long long int q,w,e,r,t;
char a,s[100000000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>q;
	int o=0;
	for(int i=1;i<=q;i++){
		cin>>w;
		cin>>a;
		for(;o<=w+e;o++){
			s[o]=a;
		}
		e=o-1;
		t=t+w;
	}
	for(int i=1;i<=t/2+1;i++){
		for(int o=t;o>=t/2+1;o--){
			if(s[i]!=s[o]){
				s[o]=s[i];
				r++;
				i++;
			}
		}
	}
	cout<<r;
	return 0;
} 
