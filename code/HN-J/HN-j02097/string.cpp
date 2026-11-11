#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],cnt,z;
char c[200010];
string f,s;
bool turn(string s){
	int l=s.size();
	bool t=1;
	for(int i=0,j=l-1;j>=0;i++,j--){
		f[i]=s[j];
	}
	if(s==f) return 1;
	return 0;
}
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		z=a[1];
		cin>>c[i];
		if(z!=a[i]) t1=0;		
	}
	if(t1==1){
		for(int i=0,j=n;i<=n/2;i++,j--){
			if(c[i]!=c[j]) cnt++;
		}
		cout<<cnt*z;
		return 0;
	}
	for(int i=1;i<=n;i++){
		while(a[i]>0){
			s+=c;
			a[i]--;
		}
	}
	if(turn(s)==1){
		cout<<0;
		return 0;
	}	
	int l=s.size();
	for(int i=0;i<=l/2;i++){
		if(f[i]!=s[i]) cnt++;
	} 
	cout<<cnt;
	return 0;
}
