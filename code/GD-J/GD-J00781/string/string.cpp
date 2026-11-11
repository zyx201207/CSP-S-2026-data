#include<bits/stdc++.h>
using namespace std;
const long long K=2e5+5;
long long a[K];
char c[K];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	long long sum=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	const long long L=s.size();
	if(L%2==0){
		for(int i=1;i<L/2+1;i++){
			if(s[i]==L+1-i){
				cout<<"0";
			}else{
				sum++;
			}
		}
	}else{
		for(int i=1;i<=L/2;i++){
			if(s[i]==L+1-i){
				cout<<"0";
			}else{
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
