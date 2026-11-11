#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string qq_str;
	string qq_pz;
	long long qq_n=0;
	cin>>qq_n;
	long long qq_cut=0;
	for(long long i=0;i<qq_n;i++){
		cin>>qq_cut>>qq_pz;
		for(long long j=0;j<qq_cut;j++){
			qq_str+=qq_pz;
		}
	}
	qq_cut=0;
	for(long long i=0,j=(qq_str.size()-1);i<j;i++,j--){
		if(qq_str[i]!=qq_str[j]) qq_cut++;
	}
	cout<<qq_cut;
	return 0;
}
