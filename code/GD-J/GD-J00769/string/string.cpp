#include<bits/stdc++.h>
using namespace std;
long long n,z,q;
string s;
struct db{
	long long a;
	char b;
}lht[200005];
bool pd(string a){
	for(int i=0;i<a.size()/2;i++){
		if(a[i]==a[a.size()-1-i]){
			continue;
		}else{
			return false;
		}
	}
	return true;
}
void cz(long long a,char b){
	for(long long i=0;i<a;i++){
		s+=b;
	}
}
void th(string a){
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			z++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>lht[i].a>>lht[i].b;
	}
	for(int i=0;i<n;i++){
		cz(lht[i].a,lht[i].b);
	}
	if(pd(s)){
		cout<<"0";
		return 0; 
	}
	th(s);
	cout<<z;
	return 0;
}
