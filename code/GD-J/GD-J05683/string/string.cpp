#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in",cin,in);
	freopen("travel.in",cout,out);
	string a;
	char f;
	long long s=0,d=0,g=0;
	cin>>s;
	for(int i=0;i<s;i++){
		cin>>d>>f;
		g=g+d;
		for(int j=0;j<d;j++){
			a[j]=f;
		}
	}
	s=0;
	for(int i=0,j=g;i<g-1;i++,j--){
		if(a[i]!=a[j]){
			s++;
		}
		
	}
	cout<<s/2;
	return 0;
}
