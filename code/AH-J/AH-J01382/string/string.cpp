#include<bits/stdc++.h>
using namespace std;
string s;
string x,y;
string S(int k,string a){
	string s={};
	for(int i=0;i<k;i++){
		s+=a;
	}
	return s;
}
int main(){
	freopen("string.in","r",sidin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	double sum=0;
	int n,k;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k>>a;
		sum+=k;
		string num=S(k,a);
		s+=num;
	}
	int ans=0;	
	for(int i=0;i<=int(sum/2);i++){
		x+=s[i];
	}
	for(int i=ceil(sum/2);i<sum;i++){
		y+=s[i];
	}
	for(int i=0;i<ceil(sum/2)-1;i++){
		if(x[i]!=y[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
