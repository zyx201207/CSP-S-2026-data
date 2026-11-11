#include<bits/stdc++.h>
using namespace std;

int a[200009];
string s[200009];


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=0;i<=n;i++){
		int sum=a[i];
		while(sum){
			if(sum%2==0) s[i]+='0';
			else s[i]+='1';
			sum/=2;
		}
		string d=s[i];
		for(int j=s[i].size();j>0;j--){
			int w=0;
			s[i][w]=d[j];
		}
		cout<<s[i]<<endl;
	}
	
	
	return 0;
}
