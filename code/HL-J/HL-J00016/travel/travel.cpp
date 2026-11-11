#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,aa,b,bb;
	cin>>a>>aa>>b>>bb;
	bool f=0;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
		f=1;
	}
	string t1,t2;
	t1=t1+aa[0]+aa[1];
	t2=t2+bb[0]+bb[1];
	if(t1==t2&&!f){
		cout<<1;
	}else{
		cout<<0;
		f=1;
	}
	if(aa[2]<='C'){
		if(bb[2]<='C'&&!f){
			cout<<1;
		}else{
			cout<<0;
			f=1;
		}
	}else{
		if(bb[2]<='C'||f==1){
			cout<<0;
			f=1;
		}else{
			cout<<1;
		}
	}
	int k1=int(aa[2]),k2=int(bb[2]);
	if(abs(k1-k2)==1&&!f){
		if(k1==67&&k2==68||k1==68&&k2==67){
			cout<<0;
			f=1;
		}else{
			cout<<1;
		}
	}else{
		cout<<0;
	}
	return 0;
}