#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
int kill=0;
int j=0;
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
void work(){
	for(int i=1;i<=n;i++){
		if(a[i]>a[j]){
			kill++;
			j++;
		}
	}
	cout<<n-kill;
}
int main(){
	init();
	work();
	return 0;
} 
