#include<bits/stdc++.h>
using namespace std;
char s,d;
long long a,f,g;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>f>>d;
	if(a==f&&a!=17&&f!=17&&a!=01&&f!=01){
		if(a==01||f==01){
			g==1;
		}
		else{
			g==0;
		}
		cout<<1<<1<<1<<g;
	}
	 else if(a!=f){
		cout<<"000";
		if(a==01&&f==01){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
