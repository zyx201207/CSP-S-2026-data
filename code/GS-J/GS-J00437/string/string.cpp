#include<bits/stdc++.h>
using namespace std;
//const int N=2e5+10;
//const long long M=2e9+10;

int a=0;
string s;
//char m[M];
//long long cnt= -1;
string m;

void ad(long long n,string s1){
	for(long long i=1;i<=n;i++){
		m+=s1;
//		cnt++;
		
		
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  n;
	cin>>n;
	long long sum=0;
	
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		ad(a,s);
		
	}
	
//	for(int i=1;i<=cnt;i++){
//		cout<<m[i];
//		
//	}
	for(long long i=0;i<m.size()/2;i++){
		if(m[i]!=m[m.size()-i]){
			sum+=1;
//			cout<<m[i]<<" "<<m[cnt-i]<<endl;
			
		}
	}
	cout<<sum;
	
	return 0;
	
} 
