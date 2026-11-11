#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string c,num="",fann="";
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		num+=c;
	}
	for(int j=num.size()-1;j>=0;j--){
		fann+=num[j];
	}
	if(num==fann){
		cout<<0;
	}else{
		if(num.size()%2==0){
			for(int i=0;i<=num.size()/2;i++){
				if(num[i]!=fann[i]){
					sum+=1;
				}
			}
		}else{
			for(int i=0;i<=num.size()/2+1;i++){
				if(num[i]!=fann[i]){
					sum+=1;
				}
			}
		}
		cout<<sum;		
	}
	
	
	return 0;
} 
