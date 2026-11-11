#include<bits/stdc++.h>
using namespace std;
string s1,s2;
bool flag=1;
int a,n,lon1,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		char x;
		cin>>x;
		for(int i=1;i<=a;i++){
			s1+=x;
		}
		lon1+=a;
	}
	for(int i=lon1-1;i>=0;i--){
		s2+=s1[i];
	}
	for(int i=0;i<lon1;i++){
		if(s1[i]!=s2[i]){
			s1[i]=s2[i];
			s2[lon1-i-1]=s2[i];
			sum++;
		}
	}
	cout<<sum;
	//cout<<s1<<endl<<s2;
	return 0;
}
