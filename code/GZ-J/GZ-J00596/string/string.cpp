//GZ-J00596,遵义市第四初级中学,杨泓钦 
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	
	int n,k;
	cin>>n;
	string s;
	string re="";
	for(int i=1;i<=n;i++){
		cin>>k>>s;
		for(int i=1;i<=k;i++){
			re=re+s;
		}
	}
	long long sum=0;
	for(int i=0,j=re.size()-1;i<=re.size(),j>=0;i++,j--){
		if(re[i]!=re[j])sum++;
	}
	cout<<sum/2;
} 
