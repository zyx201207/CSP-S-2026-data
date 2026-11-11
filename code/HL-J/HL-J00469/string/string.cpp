#include<iostream>
#include<cstring>
using namespace std;
string s1,s2;
int l1;
char d[100000];
int main(){
	int n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a,h=0;
	char b;
	l1=strlen(d);
	int l1=strlen(d);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			d[h+a]=b;
		}
		h+=a;
	}
	int s=0,t=1;
	for(int i=1,j=l1;i<=l1,j>0;i++,j--){
		if(s1[i]!=s1[j]){
			 t=0;
		}
	}
	if(t==0){
		for(int i=1,j=l1;i<=l1,j>=1;i++,j--){
			if(d[i]!=d[j]){
				d[j]=d[i];
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}
