#include<bits/stdc++.h>
using namespace std;
int n,cut;
string l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		while(a--)l+=c;
	}for(int i=0;i<=(l.size()-1)/2;i++){
		if(l[i]!=l[l.size()-1-i])cut++;	
	}cout<<cut;
	return 0;
}
