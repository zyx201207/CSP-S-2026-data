#include<bits/stdc++.h>
using namespace std;
struct str{
	int t;
	char c;
};
str a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,num=0,d=0,j;
	char c;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].t>>a[i].c;
		num+=a[i].t;
	}
	if(n==1){
		cout<<0;
		return 0;
	}j = n;
	num/=2;
	for(int i = 1;i<=n;i++){
		int b = min(a[i].t,a[j].t);
		a[i].t-=b;
		a[j].t-=b;
		if(a[i].c!=a[j].c){
			if(d+b>num){
				cout<<num;
				return 0;
			}else d+=b;
		}
		if(a[j].t==0){
			j--;i--;
		}
		if(i>=j){
			cout<<d;
			return 0;	
		}	
	}
	cout<<d;
	return 0;
}
