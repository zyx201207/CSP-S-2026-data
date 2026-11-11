#include<iostream>
#include<string>
using namespace std;
char abc,c[100000005];
long long n,m,b,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>abc;
		for(int i=d;i<d+m;i++){
			c[i]=abc;
		}
		d+=m;
	}
	for(int i=0;i<d/2;i++){
		if(c[i]!=c[d-i-1])b++;
	}
	cout<<b;
	return 0;
}
