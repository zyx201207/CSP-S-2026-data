#include<bits/stdc++.h>
using namespace std;
//HN-02278
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,cs=0;
	char c;
	string l="";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			l+=c;
		}
	}
	for(int i=0;i<l.size()/2;i++){
		if(l[i]!=l[l.size()-1-i]){
			l[l.size()-1-i]==l[i];
			cs++;
		}
	}
	cout<<cs;
	return 0;
}
