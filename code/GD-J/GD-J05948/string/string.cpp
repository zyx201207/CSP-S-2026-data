#include<iostream>
using namespace std;
string a;
int n,cnt,v=1,w,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		char f;
		cin>>k>>f;
		for(int j=w+1;j<=w+k;j++) a[j]=f;
		w+=k; 
	}
	s=w;
	for(int i=1;i<=s;i++){
		if(a[v]!=a[w]){
			cnt++;
			a[v]=a[w];
		}
		v++;
		w--;
	}
	cout<<cnt;
	return 0;
}
