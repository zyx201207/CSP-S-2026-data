#include<bits/stdc++.h>
using namespace std;
vector<char> w;
int main(){
	("string.in",stdin);
	("string.out",stdout);
	int n;
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++) w.push_back(c);
	}
	long long sum=0;
	if(w.size()%2==0){
		for(int i=0;i<=w.size()/2-1;i++){
			for(int j=w.size()/2+1;j<=w.size();j++){
				if(i+j==w.size()-1){
					if(w[j]!=w[i]){
					w[j]==w[i];
					sum++;	
					}
				}
			}
		}	
	}
	else{
		long long mid=w.size()/2;
		for(int i=0;i<=mid-1;i++){
			for(int j=mid+1;j<=w.size();j++){
				if(i+j==2*mid){
					if(w[j]!=w[i]){
					w[j]==w[i];
					sum++;	
					}
				}
			}
		}	
	}
	cout<<sum;
	return 0;
}
