//GZ-J00403 ∂≠≤©”Ó 
#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
bool f=1;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int v;char c;
		cin>>v>>c;	
		while(v--){
			s+=c;
		}
	}
	//cout<<s;
	int id=0;//3 2a 2b 1c
	//aabbc
	for(int i=s.size()-1;i>(s.size())/2;i--){
		//cout<<s[i]<<' '<<s[id]<<'\n';
		if(s[i]!=s[id])ans++;
		id++;
	}
	cout<<ans;
	return 0;
}
