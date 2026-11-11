#include<bits/stdc++.h>
using namespace std;
struct a{
	long long s;
	char z;
}b[200000];	
long long sum=0;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].s>>b[i].z;
	} 
	if(n==1){
		cout<<0;
	}
	else{
	
		int i=1;int j=n;
		while(i<j){
			if(b[i].z!=b[j].z){
				if(b[i].s>b[j].s){
					sum+=b[j].s;
					b[i].s-=b[j].s;
					j--;
				}
				else if(b[i].s<b[j].s){
					sum+=b[i].s ;
					b[j].s-=b[i].s;
					i++;
				}
				else{
					sum+=b[i].s;
					i++;
					j--;
				}
			}
			else{
				if(b[i].s>b[j].s){
					b[i].s-=b[j].s;
					j--;
				}
				else if(b[i].s<b[j].s){
					b[j].s-=b[i].s;
					i++;
				}
				else{
					i++;
					j--;
				}
			}
		} 
	}
	cout<<sum;
	return 0;
}
