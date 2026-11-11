#include<bits/stdc++.h>
using namespace std;
struct ff{
	long long a;
	char c;	
};
ff s[200005];
bool flag=false;
bool flag1=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x;
	cin>>x;
	long long sum=0;
	
	for(int i=1;i<=x;i++){
		cin>>s[i].a>>s[i].c;
		if(s[i].c==s[i-1].c){
			flag=true;
		}
		if(s[i].c!=s[i-1].c){
			flag1=true;
		}
		sum+=s[i].a;
	}
	if(x==1){
		cout<<0;
		return 0;
	}
	if(x==2){
		cout<<max((s[1].a-s[2].a)/2,(s[2].a-s[1].a)/2);
		return 0;
	}
	if(flag=false){
		cout<<sum/2;
		return 0;
	}
	if(flag1=false){
		cout<<0;
		return 0;
	}
	
	return 0;
}