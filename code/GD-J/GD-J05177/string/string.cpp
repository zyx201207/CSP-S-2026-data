#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string a;
	int cnt;
	bool f=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int x;
		char y;
		scanf("%d",&x);
		scanf("%s",&y);
		for(int j=0;j<x;++j){
			a+=y;
		}
	} 
	if(a.size()%2==0){
		int j=a.size()-1;
		for(int i=0;i<a.size()/2;i++){
			if(a[i]!=a[j]){
				cnt++;
				f=0;
			}
			j--;
		}
		if(f){
			printf("0");
			return 0;
		}
		else{
			printf("%d",cnt);
		}
	}
	else{
		int j=a.size()-1;
		for(int i=0;i<a.size()/2+1;i++){
			if(a[i]!=a[j]){
				cnt++;
				f=0;
			}
			j--;
		}
		if(f){
			printf("0");
			return 0;
		}
		else{
			printf("%d",cnt);
		}
	}
} 

