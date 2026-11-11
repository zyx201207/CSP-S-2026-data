#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t,t1;
int k,k1;
bool check(char a,char b){
	if(a>='A' && a<='C' && b>='A' && b<='C') return 1;
	if(a>='D' && a<='E' && b>='D' && b<='E') return 1;
	return 0;
}
int p,p1;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	
	cin>>c1>>s1>>c2>>s2;
	
	
	int idx=1;
	for(int i=0;i<c1.size();i++){
		t+=pow(10,idx)*(c1[i]-'0');
		t1+=pow(10,idx)*(c2[i]-'0');
		idx--;
	}
	if(t!=t1){
		cout<<"0000";
		return 0;
	}else cout<<1;
	
	
	int idx2=1;
	for(int i=0;i<s1.size()-1;i++){
		k+=pow(10,idx2)*(s1[i]-'0');
		k1+=pow(10,idx2)*(s2[i]-'0');
		idx2--;
	}
	if(k!=k1){
		cout<<"000";
		return 0;
	}else cout<<1;
	
	
	if(check(s1[2],s2[2])) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	
	
	p=s1[2]-'A';
	p1=s2[2]-'A';
	if(abs(p-p1)<=1) cout<<1;
	else cout<<0;
	return 0;
} 
