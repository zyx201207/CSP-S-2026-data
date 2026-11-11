#include<bits/stdc++.h>
using namespace std;
int a,b,c[30],k,num=1;
char ssa;
string ppl,lpp;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>a;
	for(int q=0;q<a;q++){
		cin>>b>>ssa;
		for(int w=0;w<b;w++){
			ppl=ppl+ssa;
			c[int(ssa-'a')]+=b;
		}
	}
	for(int q=int(ppl.size())-1;q>=0;q--,k++){
		lpp+=ppl[q];
	}
	if(lpp==ppl){
		cout<<"0";
		return 0;
	}
	for(int q=0;q<26;q++){
		if(c[q]==1){
			k=q;
			break;
		}
	}
	ssa=ppl[int(ppl.size())/2];
	cout<<ssa;
	return 0;
}
