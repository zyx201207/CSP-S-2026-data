#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans,z=0;
	cin>>n;
	char s[10000000000]={};
	for(int i=0;i<n;i++){
		int m=0;
		char c;
		cin>>m>>c;
		for(int j=ans;j<m;j++){
			s[j]=c;
			ans+=1;
			}
	}
	int r=0;
	int l=ans-1;
	while(l-r<=1){
		if{s[l]!=s[r]}{
			z+=1
		}
		l--;
		r++;
	}
	cout<<z;
	return 0;
}


