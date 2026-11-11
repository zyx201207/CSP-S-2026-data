#include<bits/stdc++.h>
using namespace std;
char a[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b;
		cin>>c;
		for(int i=1;i<=b;i++){
			a[cnt+i]=c;
		}
		cnt+=b;
	}
	int l,r;
	int sum=0;
	if(cnt%2==1){
		l=cnt/2;
		r=cnt/2+2;
	}else{
		l=cnt/2;
		r=cnt/2+1;
	}
	while(l>0&&r<=cnt){
		if(a[l]!=a[r]){
			sum++;
		}
		l--,r++;
	}
	cout<<sum;
	
	return 0;
	
} 

//3
//2 a
//2 b
//1 c

