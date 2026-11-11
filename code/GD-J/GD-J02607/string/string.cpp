#include<bits/stdc++.h>

using namespace std;
char a[200001],fa[200001];
long long b[200001],fb[200001];
long long n,cnt=0,j=1;
int main(){
	ifstream("D:\GD-J02607\string\string.in");
	ofstream("D:\GD-J02607\string\string.out");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		fb[n+1-i]=b[i];
		fa[n+1-i]=a[i];
	}
	int j=1;
	int i=1;
	while(i<=n){
		if(b[i]==0)i++;
		if(b[i]>=fb[j]){
			if(a[i]!=fa[j]){
				cnt+=fb[j];
			}
			b[i]-=b[j];
			j++;
		}
		else{
			if(a[i]!=fa[j]){
				cnt+=b[i];
			}
			fb[j]-=b[i];
			i++;
		}
	}
	cout<<cnt/2;
}
