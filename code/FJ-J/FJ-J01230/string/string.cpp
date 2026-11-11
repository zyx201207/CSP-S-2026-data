#include<bits/stdc++.h>
using namespace std;
int main(){
	string a1[100000];
	string a2;
	long long int m,n,ans=0;
	string m1;
	cin>>n;
	int len_a=0;
	for(int i=0;i<n;i++){
		cin>>m>>m1;
		for(int j=0;j<m;j++){
			a1[ans]=m1;
			ans++;
		}
		len_a+=m;
	}
	int sum=0;
	/*cout<<len_a<<endl;
	for(int i=0;i<len_a;i++){
		cout<<a1[i];
	}
	cout<<endl;*/
	if(len_a%2==0){
		for(int i=0;i<len_a/2;i++){
		    if(a1[i]!=a1[len_a-1-i])
		       sum++;
	}
	}   
	else {
		for(int i=0;i<(len_a-1)/2;i++){
			if(a1[i]!=a1[len_a-1-i])
			   sum++;
		}
	}
	cout<<sum;
	return 0;
}
