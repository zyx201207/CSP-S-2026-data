#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n;
	cin>>n;
	unsigned long long li_n=n;
	string a;
	unsigned long long i=1,sum=0;
	while(li_n--){
		unsigned long long num;
		cin>>num;
		sum+=num;
		char ch;
		cin>>ch;
		a.insert(a.end(),num,ch);
	}
	unsigned long long cnt=0;
	for(unsigned long long i=0;i<sum/2;i++){
		if(a[i]!=a[sum-i-1]){
			cnt++;
		}
    }
	cout<<cnt<<endl;
	return 0;
} 
