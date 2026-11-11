#include <bits/stdc++.h>
using namespace std;
int n;
char a[1000005],b;
long long num,sum=0;
bool flag=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		sum+=num;
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		b=a[1];
		if(a[i]!=b){
			flag=0;
		}
	}if(flag==1){
		cout<<0;
	}else{
		cout<<(sum-1)/2;
	} 
	return 0;
} 
