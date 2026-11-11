#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string s,k;
	for(int i=0;i<b.size()-1;i++) s+=b[i];
	for(int i=0;i<d.size()-1;i++) k+=d[i];
	int lb=b.size(),ld=d.size();
	if(s==k){
		cout<<1;
		if((b[lb-1]>='A'  && b[lb-1]<='C'&& d[ld-1]<='C' && d[ld-1]>='A')|| (b[lb-1]>='D' && b[lb-1]<='E' && d[ld-1]>='D' && d[ld-1]<='E')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<0;
	}
	if((abs(b[b.size()-1]-d[d.size()-1])!=1) || (d[d.size()-1]=='C' && b[b.size()-1]=='D') || (d[d.size()-1]=='D' && b[b.size()-1]=='C') || s!=k) cout<<0;
	else cout<<1;
	return 0;
}
