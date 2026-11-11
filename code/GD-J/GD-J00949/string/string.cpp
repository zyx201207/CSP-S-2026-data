#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long a;
	char s;
}s[200003];
int n;
long long lo,ans;
char c;
int check(){
	int num=0;
	while(num<lo/2){
		num++;
		int h=0;
		char l,r;
		for(int i=1;i<=n;i++){
			h+=s[i].a;
			if(h>=num){
				l=s[i].s;
				break;
			}
		}
		h=0;
		for(int i=n;i>=1;i--){
			h+=s[i].a;
			if(h>=num){
				r=s[i].s;
				break;
			}
		}
		if(l!=r){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].s;
		lo+=s[i].a;
	}
	cout<<check();
	return 0;
}
