#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2;
string s1,s2;
struct seat{
	ll k;
	char q;
};
seat tra(string p){
	seat se;
	se.k=0;
	for(int i=0;i<2;i++){
		se.k+=p[i]-'0';
		se.k*=10;
	}se.q=p[2];
	if(se.q=='D')se.q='Y';
	else if(se.q=='F')se.q='Z';
	return se;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	seat se1=tra(s1),se2=tra(s2);
	if(c1==c2){
		cout<<1;
		if(se1.k==se2.k){
			cout<<1;
			if(abs(int(se1.q-se2.q))<=2){
				cout<<1;
				if(abs(int(se1.q-se2.q))==1)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

