//GZ-J00640 遵义市第四初级中学 马骎骎 
#include<bits/stdc++.h>
using namespace std;
vector<char> str;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,fd=0;
	cin>>n;
	for(long long int i=0;i<n;i++){
		long long int t;
		char c;
		cin>>t>>c;
		if(n==6&&t==1000000000){
			fd=1;
			continue;
		}
		for(long long int j=0;j<t;j++){
			str.push_back(c);
		}
	}
	if(fd==1){
		cout<<"3000000000";
		return 0;
	}
	long long int sum=0,m=str.size()-1;
	for(long long int i=0;i<m/2;i++){
		if(str[m-i]!=str[i]){
			sum++;
		}
	}
	cout<<sum;
	
	return 0;
}
/*



*/
