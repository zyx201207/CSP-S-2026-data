#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	int n,i,j,cnt=0,c=0;
	int a[200000];
	string s[200000];
	fin>>n;
	for(i=0;i<n;i++){
		fin>>a[i]>>s[i];
	}
	string w[100000000];
	for(i=0;i<n;i++){
		for(j=0;j<a[i];j++){
			w[cnt]=w[i];
			cnt++;
		}
	}
	if(cnt%2==0){
		for(i=0;i<cnt/2;i++){
			if(w[i]!=w[cnt-i-1]){
				c++;
			}
		}
	}
	else{
		for(i=0;i<cnt/2-1;i++){
			if(w[i]!=w[cnt-i-1]){
				c++;
			}
		}
	}
	fout<<c;
	fin.close();
	fout.close();
	return 0;
}
