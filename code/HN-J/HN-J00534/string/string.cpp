#include <bits/stdc++.h>
using namespace std;
string str="";
int n,m,ans,l;
char c;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdin);
	//ysjfNB
	cin>>n;
	while(n--){
		cin>>m>>c;
		l+=m; 
		while(m--){
			str+=c;
		}
	} 
	//cout<<str<<"..."<<l<<"   "; 
	for(int i=0;i<=l/2-1;i++){
		ans+=int(str[i]!=str[l-i-1]);
		//cout<<i<<"   "<<l-i-1<<endl;
	}
	cout<<ans;
	return 0;
}
