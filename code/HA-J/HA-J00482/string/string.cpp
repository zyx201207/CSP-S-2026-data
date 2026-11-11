#include<bits/stdc++.h>
using namespace std;
int n;
struct bb{
	int q;
	char s;
}a[200005];
long long cnt;
string s1;
bool b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].q>>a[i].s;
	}
	for(int i=2;i<=n;i++){
		if(a[i].s!=a[i-1].s) b=1;
	}
	if(b==0||n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].q;j++){
			s1+=a[i].s;
		}
	}
//	for(int i=0;i<=s1.size();i++){
//		if(s1[i]==' ')cout<<"w";
//		else cout<<s1[i];
//	}
	if(s1.size()%2==1){
		for(int i=0;i<s1.size()/2;i++){
			if(s1[i]!=s1[s1.size()/2+i+1]) cnt++;
		}
	}
	else{
		for(int i=0;i<s1.size()/2;i++){
			if(s1[i]!=s1[s1.size()-i-1]) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
//3
//1 a
//2 b
//1 a
