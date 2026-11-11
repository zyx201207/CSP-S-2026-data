#include<bits/stdc++.h>
using namespace std;
long long a1,s1,s2;
string a2,s3,s4;
string D;
const int N=1e9;
long long y=N;
int sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		cin>>s1>>s3>>s2>>s4;
		if(s3==s4){
			cout<<"0";
			return 0;
		}
		cout<<min(s1,s2);
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a1>>a2;
		if(y==a1){
			y+=a1;
			sum++;
		}
		if(sum==0){
			y=min(y,a1);
		}
		sum=0;
	}
	cout<<y;
}
