#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long num=0;
	long long num1=0;
	long long n2=0;
	long long e2=0;
	long long num2[200005]={0};
	char bb[200005]={0};
	long long num3=0;

	for(int i=0;i<n;i++){
		cin>>num2[i]>>bb[i];
	}
	e2=n-1;
	for(int i=0;i>=0;i++){
		
		if((num2[n2]-num)<=0){
				n2++;
				num=0;
		}
		if((num2[e2]-num1)<=0){
				e2--;
				num1=0;
		}
		if(n2>=n/2){
			break;
		}
		if(bb[n2]!=bb[e2]){
			num++;
			num1++;
			num3++;
		}else{
			num++;
			num1++;
		}
	}
	cout<<num3;
	return 0;
}
