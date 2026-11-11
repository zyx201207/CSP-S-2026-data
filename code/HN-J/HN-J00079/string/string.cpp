#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	int n[a];
	string m[a];
	for(int i=0;i<a;i++){
		cin>>n[i]>>m[i];
	}
	long long num=0;
	for(int i=0;i<(a/2);i++){
		if(m[a-i-1]!=m[i]){
			num+=n[a-i-1];
		}
	} 
	if(a%2==1){
		num+=n[a-(a/2)];
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
