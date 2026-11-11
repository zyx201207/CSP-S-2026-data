#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,S=0;
	string l;
	char s;
	cin>>a;
    for(int i=0;i<=a-1;i++){
    	cin>>b>>s;
    	l[i]=b*s;
	}
	if(l[a-1]==l[0]&&l[a-1-1]==l[1]){
		cout<<S;
	}
	else{
		for(int j=0,z=0;j<=a,z<=a/2;j++,z++){
			if(l[j]!=l[a-z]){
				S++;
			}
		}
	}
	cout<<S;
	return 0;
}
