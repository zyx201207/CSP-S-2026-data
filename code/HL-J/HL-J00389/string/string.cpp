#include<bits/stdc++.h>
using namespace std;
int n;
unsigned long long num,len,sum;
string s,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		cin>>a;
		for(int j=1;j<=num;j++){
			s+=a;
		}
		len+=num;
	}
	if(len%2==0){
		for(unsigned long long i=0,j=len-1;i<=((len/2)-1),j>=(len/2);i++,j--){
			if(s[i]!=s[j]){
				sum++;
			}
		}
	}
	else{
		for(unsigned long long i=0,j=len-1;i<=((len/2)-1),j>=((len/2)+1);i++,j--){
			if(s[i]!=s[j]){
				sum++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
