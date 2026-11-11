#include<iostream>
using namespace std;
long long tmp,l,r,cnt,n;
char ch,f;
string s="";
bool flag=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	scanf("%lld",&n);
	for(long long i=1;i<=n;++i){
		cin>>tmp>>ch;
		if(i==1) f=ch;
		else{
			if(f!=ch) flag=false;
		}
		for(long long j=1;j<=tmp;++j){
			s+=ch;
		}
	}
	if(flag){
		printf("0");
		return 0;
	}
	l=0;
	r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	printf("%lld",cnt);
	return 0;//freopen结束前注释要删掉！！！ 并保存！！！ 
}

