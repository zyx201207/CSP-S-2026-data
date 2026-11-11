#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,w,q=-1;
	string s;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			w= s[j] | s[j+1];
			if(w>q){
				q=w;
			}
		}
	}
	cout<<q;
	return 0;
}
