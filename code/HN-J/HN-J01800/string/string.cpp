#include<bits/stdc++.h> 
using namespace std;
struct s{
	int a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	s s[n+10];
	for(int i=1;i<=n;i++){
		cin>>s[i].a >>s[i].c ; 
	}
	int ans=0;
	for(int i=1,j=n,t=0;i<j;){
		if(s[i].c==s[j].c){
			t=min(s[i].a,s[j].a);
			s[i].a -=t;
			s[j].a -=t;
		}else{
			t=min(s[i].a,s[j].a);
			s[i].a-=t;
			s[j].a -=t;	
			ans+=t;
		}
		if(s[i].a ==0){
			i++;
		}
		if(s[j].a==0 ){
			j--;
		}
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
