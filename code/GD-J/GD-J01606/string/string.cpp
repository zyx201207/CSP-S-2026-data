#include<iostream>
using namespace std;
char num[100000005];
long long top=1;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int a=1;a<=n;a++){
		int x;
		char y;
		cin>>x>>y;
		for(int b=1;b<=x;b++){
			num[top]=y;
			top++;
		}
	}
	for(int a=1;a<=(top-1)/2;a++){
		if(num[a]!=num[top-a]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
