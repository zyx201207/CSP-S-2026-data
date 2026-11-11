#include <bits/stdc++.h>;
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin>>n;
    string s,S;
    for(int i=0;i<n;i++){
    	cin>>m>>s;
    	for(int j=0;j<m;j++){
    		S+=s;
		}
	}
	int r=S.length();
	int p=0;
	int q=0;
	if(r%2==1)	{	
		r=S.length()/2;
		int l;
		l=r;
		while(r<S.length()){
			l--;
			if(S[r]==S[l]){
				p+=1;
			}
			else q++;
			r++;
		}
		if(p==S.length()-1) cout<<0;
		else cout<<q-1;
	}
	else {
		r=S.length()/2;
		int l=r-1;
		while(r<S.length()){
				l--;
			if(S[r]==S[l]){
				p+=1;
			}
			else q+=1;
			r++;
		}
		if(p==S.length()-1) cout<<0;
		else cout<<q;
	}
	return 0;

}