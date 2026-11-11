#include<bits/stdc++.h>
using namespace std;
string write(string x,string y,long long z){
	if(z==0){
		return y;
	}else{
		y+=x;
		return write(x,y,z-1);
	}
}
int main(){
	long long n,a1,half_,s_long=0,temp=0,sum=0,t1=0,a2=0;
	string S="",c1,S1="",S2="";
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a1>>c1;
		s_long+=a1;
		half_+=(a1/2);
		if(a1%2==1){
			t1++;
		}
		if(t1==2){
			half_++;
			t1=0;
		}
		S+=write(c1,S2,a1);	
	}
	for(long long i=0;i<half_;i++){
		S1+=S[i];
	}
	for(long long i=s_long-1;i>=s_long-half_;i--){
		if(S[i] != S1[temp]){
			sum++;
		}
		temp++;
	}
	cout<<sum;
	return 0;
} 
