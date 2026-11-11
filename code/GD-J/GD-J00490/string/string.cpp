#include <bits/stdc++.h>
using namespace std;
string x[200000]={};
int n[200000]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long s=0,k;
	cin>>k;
	for(long long i=0;i<k;i++){
		cin>>n[i]>>x[i];
	}
	long long x1=n[0],x2=n[k-1];
	for(long long i=0,j=k-1;;){
		if(i>=j){
			break;
		}
		if(x[i]==x[j]){
			if(x1>x2){
				x1=x1-x2;
				j--;
				x2=n[j];
			}
			else if(x1<x2){
				x2=x2-x1;
				i++;
				x1=n[i];
			}
			else{
				i++;
				j--;
				x1=n[i];
				x2=n[j];
			}
		}
		else if(x[i]!=x[j]){
			if(x1>x2){
				x1=x1-x2;
				s=s+x2;
				j--;
				x2=n[j];
			}
			else if(x1<x2){
				x2=x2-x1;
				s=s+x1;
				i++;
				x1=n[i];
			}
			else{
				s=s+x1;
				i++;
				j--;
				x1=n[i];
				x2=n[j];
			}
				
		}
	}
	cout<<s<<endl;
	return 0;
}
