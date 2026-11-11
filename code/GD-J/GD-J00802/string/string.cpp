#include<bits/stdc++.h>
using namespace std;
long long int n,a,sum,num;
char d;
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>d;
		sum+=a;
		while(a--){
			x=x+d;
		}
	}
	long long int z=(sum+1)/2;
	for(long long int i=0,j=sum-1;i<z;i++,j--){
		if(i==j){
			break;
		} 
		if(x[i]!=x[j]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
