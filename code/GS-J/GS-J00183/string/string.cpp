#include<bits/stdc++.h>
using namespace std;
struct c{
	long long a;
	string s;
};
c S[1001];
int n,sum=0,ant=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>S[i].a>>S[i].s;
	}
	for(int i=1;i<n/2;i++){
		char sl=S[i].s;
		char sr=S[n-i+1].s;
		int al=S[i].a;
		int ar=S[n-i+1].a;
		if(sl!=sr||al!=ar){
			if(al>ar&&sl!=sr){
				sum=sum+ar;
				if(sl!=S[n-i].s){
					sum=sum+al-ar;
				}
			}
			if(al<ar&&sl!=sr){
				sum=sum+al;
				if(sr!=S[i+1].s){
					sum=sum+ar-al;
				}
			}
			if(al==ar&&sl!=sr){
				sum=sum+al;
			}
			
			if(al>ar){
				if(sl!=S[n-i].s){
					sum=sum+al-ar;
				}
			}
			if(al<ar){
				if(sr!=S[i+1].s){
					sum=sum+ar-al;
				}
			}
		}
	}
	cout<<sum;
}
