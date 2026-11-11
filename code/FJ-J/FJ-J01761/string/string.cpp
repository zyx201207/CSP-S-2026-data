#include<bits/stdc++.h>
using namespace std;
char a[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,num=1,sum=0;
	char x;
	cin>>n;
	while(n--){
		cin>>m>>x;
		for(int i=1;i<=m;i++){
			a[num]=x;
			num++;
		}
	}
	for(int i=1;i<=num/2;i++){
		if(a[i]!=a[num-i]){
			sum++;
		}
	}
	cout<<sum;
}
