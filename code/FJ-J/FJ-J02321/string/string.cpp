#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int k[200001];
char a[200001];
int main(){
	string S="";
	int n, c=0;
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i]>>a[i];
		
		S.insert(S.end(), k[i], a[i]);
	}
	n=S.length();
	for(int i=0;i<n/2;i++){
		if(S[i]!=S[n-i-1]){
			c++;
		}
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
