#include <bits/stdc++.h>
using namespace std;

long long s[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	long long n, m;
	cin>> n>> m;
	
	for(int i=0; i<n; i++){
		cin>> s[i];
	}
	
	int g;
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(s[j]>s[i]){
				g=s[i];
				for(int num=i; num>j; num--){
					s[num]=s[num-1];
				}
				s[j]=g;
			}
		}
	}
	
	int num=0, k=0;
	for(int i=0; i<n; i++){
		for(int j=i-1; j>=0; j--){
			if((s[i]-s[j])<=m){
				num++;
				m-= s[i]-s[j];
			}
			else{
				break;
			}
		}
		if(num>k){
			k=num;
			num=0;
		}
	}
	
	cout<< k;

	return 0;
}
