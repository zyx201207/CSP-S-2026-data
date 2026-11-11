#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s;
int sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	int st,la;
	if(s.size()%2==0){
		st=s.size()/2-1;
		la=s.size()/2;
	}
	else{
		st=s.size()/2;
		la=st;
	} 
	cout<<s<<" "<<st<<" "<<la<<endl;
	for(int i=0,j=s.size()-1;i<=st,j>=la;i++,j--){
		if(s[i]!=s[j]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}




