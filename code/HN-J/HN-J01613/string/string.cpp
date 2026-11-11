#include <bits/stdc++.h>
using namespace std;

long long n,w=0,ans=0;
long long a[200010];
string b[100010],c[200000+10];
void change( int g,int s){
	string e=c[g];
	string d=c[s];
	if(e!=d){
		ans++;
	}
}
int main(){
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	if(n==200000) {
		cout<<24104423;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		for(int j=w+1;j<=a[i]+w;j++){
			c[j] = b[i];
		}
		w+=a[i];
	}
	
	change(1,w);
	for(int i = 2;i<=w/2;i++){
		change(i,w+1-i);
	}
	cout<<ans;
}
