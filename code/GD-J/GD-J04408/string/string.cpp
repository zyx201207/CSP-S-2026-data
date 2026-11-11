#include<iostream>
using namespace std;
int main(){
	long long s,r = 0,small = 0,z = 0;
	cin>>s;
	long long a[s];
	char c[s];
	
	for(int i = 0;i<s;i++){
		cin>>a[i]>>c[i];
		r+=a[i]/100000;
		small+=a[i]%100000;
	}
	char all[r*100000+small];
	long long k = 0;
	for(int j = 0;j<s;j++){
		for(int i = 0;i<a[j];i++){
		all[k]=c[j];
		k++;
		
	
	}
	}
	for(int i = 0;i<(r*100000+small)/2;i++){
		if(all[i]!=all[r*100000+small-i-1]){z++;
		
		}
		
		
	}
	
	cout<<z;
	return 0;
}
