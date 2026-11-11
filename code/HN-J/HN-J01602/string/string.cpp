#include<bits/stdc++.h>
using namespace std;
long long n,shu,g,o;
string a;
char zim;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shu>>zim;
		for(int o=1;o<=shu;o++){
			a+=zim;
		}
	}
	o=a.size()-1;
	for(int i=0;i<=a.size()-1;i++){
		if(i>=o){
			break;
		}else if(a[i]!=a[o]){
		    g++;	
		}
		o--;
	}
	cout<<g;
	return 0;
} 
