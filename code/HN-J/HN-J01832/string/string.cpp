#include<bits/stdc++.h>

using namespace std;

long long n,a,l=0,lb,num=0;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(long long j=0;j<a;j++){
			s+=c;
			l++;	
		}
	}
	lb=l/2;
	long long j=l-1;
	for(long long i=0;i<lb;i++){ 
		if(s[i]!=s[j]){
			num++;
		}
		j--;
	}
	cout<<num;
	return 0;
}
