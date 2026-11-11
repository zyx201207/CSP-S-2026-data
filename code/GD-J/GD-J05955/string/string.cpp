#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,len=0,m;
	char c;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=len;j<len+m;j++) a[j]=c;
		len+=m;
	}
	for(int i=0;i<len/2;i++)
		if(a[i]!=a[len-i-1]) sum++;
	cout<<sum;
	return 0;
}
