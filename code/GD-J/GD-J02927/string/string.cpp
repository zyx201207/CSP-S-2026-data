#include<bits/stdc++.h>
using namespace std;
const long long MAXS=1e9;
string s,c,x,y;
long long a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		x+=s[i];
	}
	for(int i=s.size();i>s.size()/2;i--){
		y+=s[i];
	}
	int sum=0; 
	bool flag=true;
	for(int i=0;i<=s.size();i++){
		if(s[i]==s[i+1]){
			flag=true;
		}
		else
		{
			flag=false;
			break;
		}
	}
	if(flag==true){
		cout<<sum;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(x[i]==y[i]){
			continue;
		}
		else
			sum++;
	}
	cout<<sum;
	return 0;
} 
