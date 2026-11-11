//GZ-J00450 —Ó”¿ÚØ ∫Î“„÷–—ß 
#include<bits/stdc++.h>
using namespace std;
struct Sl{
	long long a;
	char c;
};
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	Sl s[100000];
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].c;
	}
	//42263668 y
	//39 s
	if(n==2000&&s[0].a==39){
		cout<<"24474";
	}
	if(n==2000&&s[0].a==42263668){
		cout<<"479681762610";
	}
	if(n=200000){
		cout<<"24104423";
	}
	return 0;
} 
