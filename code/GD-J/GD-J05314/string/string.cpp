#include<bits/stdc++.h>
using namespace std;
long long sum=0;

bool r(string a){
	string ca="";
	string cb="";
	for(int i=0;i<sum;i++){
		ca.append(1,a[i]);
	}
	for(int i=sum-1;i>=0;i--){
		cb.append(1,a[i]);
	}
	return (ca == cb);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long num;
	char q;
	string s;
	long long used=0;
	
	for(int i=0;i<n;i++){
		cin>>num>>q;
		sum+=num;
		
		
		s.append(num,q);
	}
	if (r(s)){
		cout<<0;
		return 0;
	}else{
		cout<<sum/2;
	}
	return 0;
} 
