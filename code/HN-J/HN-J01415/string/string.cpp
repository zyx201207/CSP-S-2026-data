#include<bits/stdc++.h>
using namespace std;
int n,a,num,sum;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		num+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	if(num%2==1){
		int j=num/2;
	
		for(int i=num/2;i<num;i++){
			if(s[i]!=s[j]){
				sum++;
				
			}
			j--;
		}
	}
	cout<<sum;
	return 0;
}
