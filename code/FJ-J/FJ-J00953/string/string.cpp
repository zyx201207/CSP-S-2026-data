#include<bits/stdc++.h>
using namespace std;
int shu[200010];

int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	int n;
	int shu,sum=0;
	string zi,ch;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>shu>>zi;
		for(int j=1;j<=shu;j++){
			ch+=zi;
		}
	}
	
	for(int i=1;i<=ch.size()/2;i++){
		if(ch[i-1]!=ch[ch.size()-i]){
			sum+=1;
		}
	}
	
	cout<<sum;
	
	
	
	
	
	
	return 0;
} 
