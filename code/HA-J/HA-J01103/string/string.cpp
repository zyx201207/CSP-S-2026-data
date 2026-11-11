#include<bits/stdc++.h>
using namespace std;
struct st{
	int a;
	char b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	st num[200005];
	string s;
	for(int i=0;i<n;i++){
		cin>>num[i].a>>num[i].b;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(num[0].b==num[1].b){
			cout<<0;
			return 0;
		}
		if(num[0].a>num[1].a){
			cout<<num[1].a;
			return 0;
		}
		cout<<num[0].a;
		return 0;
	}
	int x=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<num[i].a;j++){
			s[x]=num[i].b;
			x++;
		}
	}
	cout<<0;
	return 0;
} 
