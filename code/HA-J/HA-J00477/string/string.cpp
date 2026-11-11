#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[20000];
	vector < char > v;
	string z="";
	int n;
	long long sum=0;
	cin>>n;
	char s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		cin>>s;
		v.push_back(s);
	}
	sum=sum/2;
	long long t=0;
	int i=0;
	while(t+a[i]>=sum){
		t=t+a[i];
		i+=1;
	}
	
	
}
