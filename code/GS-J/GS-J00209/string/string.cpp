#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,q=0,a;
	string s[1000],s1;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>m>>s1;a+=m;
	    for(int j=0;j<m;j++){
	    	s[q]=s1;
	    	q++;
		}
	}q=0;
	int b=floor(a/2);
	for(int i=0;i<b;i++){
		if(s[i]!=s[a-1]){
			q++;
		}a--;
	}cout<<q;
	return 0;
}
