#include <cstdio>
#include <iostream>
using namespace std;
FILE* fout;FILE* fin;
void scan(char* a,auto b){
	fscanf(fin,a,b);
}
void prin(char* a,auto b){
	fprintf(fout,a,b);
}
int main(){
	fin=fopen("string.in","r");
	fout=fopen("string.ans","w");
	
	string s="";
	int n=0,a=0,l=0,ans=0;char c=' ';
	
	scan("%d",&n);
	cout<<n;
	for(int i=1;i<=n;i++){
		scan("%d",&a);
		scan("%s",&c);
		for(int j=1;j<=a;j++){
			s+=c;l++;
		}
	}
	for(int i=l/2;i<=n;i++){
		int w=n-i;
		if(s[i]!=s[w]){
			ans++;
		}
	}
	cout<<ans;
	prin("%d",ans);
	return 0;
}
