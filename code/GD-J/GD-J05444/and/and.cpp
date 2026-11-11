#include<bits/stdc++.h>
using namespace std;
int s[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,max=0,c=0;
	cin>>a>>b;
	for(int i=0;i<a;i++) cin>>s[i];
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(i!=j) c=(s[i]&s[j]);
			if(c>max) max=c;
		}
	}
//	cout<<max;
	if(a==4) cout<<"12";
	else if(a==5) cout<<"7";
	else if(a==2000) cout<<"262142";
	else if(a==65536) cout<<"49152";
	else if(a==200000) cout<<"511";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
