#include<bits/stdc++.h>
using namespace std;
long long n,m,q,dn;
char c;
string s,a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cin>>m>>c;
		cout<<0;
		return 0;
	}
	while(n--){
		cin>>m>>c;
		for(int i=1;i<=m;i++){
			s=s+c;
		}
	}
	q=s.size();
	if(q%2==0){
		for(int i=0;i<=q/2-1;i++){
			a=a+s[i];
		}
		for(int i=q;i>=q/2;i--){
			b=b+s[i];
		}		
	}
	if(q%2==1){
		for(int i=0;i<=q/2-1;i++){
			a=a+s[i];
		}
		for(int i=q;i>=q/2+1;i--){
			b=b+s[i];
		}		
	}	
	for(int i=0;i<=a.size()-1;i++){
		if(a[i]!=b[i]){
			dn++;
		}
	}
	cout<<dn;
	return 0;
}
