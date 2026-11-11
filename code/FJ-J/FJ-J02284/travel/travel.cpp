#include<bits/stdc++.h>
using namespace std;
bool check(char a){
	return a>='D';
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>c>>a>>d>>b;
	if(c==d){
		f1=1;
		if(a[0]==b[0]&&a[1]==b[1]){
			f2=1;
			if(check(a[2])==check(b[2])){
				f3=1;
				if(a[2]-1==b[2]||a[2]+1==b[2])f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
