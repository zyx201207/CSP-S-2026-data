#include<bits/stdc++.h>
using namespace std;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];													
	}
	string s;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	if(s.size()%2==0){
	for(int i=s.size()/2;i>=0;i--){
		int q=0;
		if(s[i-1]!=s[i+q]){
		sum++; 
		q+=3;
	}
}
}else{
	for(int i=s.size()/2;i>0;i--){
		int w=1;
		if(s[i-1]!=s[i+w]){
			sum++;
		}
		w+=3;
	}
}
cout<<sum;
return 0;
}
