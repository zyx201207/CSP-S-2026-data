#include <bits/stdc++.h>
using namespace std;
int n;
long long num_of_char[100005];
char s[100005];
long long linshi;
int result=0;
char a;
int absolute(long long n){
	return (n<0?-1*n:n);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num_of_char[i]>>s[i];
	}
	int l=0;
	int r=n-1;
	long long l_linshi,r_linshi;
	linshi=num_of_char[l]-num_of_char[r];
	while(l!=r){
		if(linshi==0){
			if(s[l]!=s[r]){
				result+=num_of_char[l];
			}
			l++;
			r--;
		}else{
			if(linshi>0){
				l_linshi=linshi;
				r_linshi=num_of_char[--r];
			}else{
				r_linshi=linshi*-1;
				l_linshi=num_of_char[++l];
			}
			linshi=l_linshi-r_linshi;
			if(s[l]!=s[r]){
				result+=absolute(linshi);
			}
		}
	}
	cout<<result;
	return 0;
}
