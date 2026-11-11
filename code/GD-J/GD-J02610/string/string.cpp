#include<bits/stdc++.h>
using namespace std;
long long n;
string a;
long long num=0;
long long mn=0;
long long x;char c;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			a[num+j]+=c;
		}
		num+=x;
	} 
	for(long long i=1;i<=num;i++){
		if(a[i]==a[num-i+1]){
			mn+=0;
		}
		else{
		mn+=1;
		} 
	}
	mn=mn/2;
	cout<<mn;
	return 0;
}
