#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int k(string a){
	int kk=0;
	kk+=10*(a[0]-'0');
	kk+=a[1]-'0';
	return kk;
}
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int n=k(s1);
	int m=k(s2);
	int n2=s1[2]-'0';
	int m2=s2[2]-'0';
	
	if(c1==c2){
		cout <<"1";
	}else{
		cout<<"0";
		
	}
	if(c1==c2 && n==m){
		cout <<"1";
	}else{
		cout<<"0";
		
	}
	if((c1==c2 && n==m) && ((1<=n2 && n2<=3 && 1<=n2 && n2<=3) || (4<=n2 && n2<=5 && 4<=n2 && n2<=5))){
		cout <<"1";
	}else{
		cout<<"0";
		
	}
	if((c1==c2 && n==m) && ((1<=n2 && n2<=3 && 1<=n2 && n2<=3) || (4<=n2 && n2<=5 && 4<=n2 && n2<=5)) && (n2+1==m2 || n2-1==m2)){
		cout <<"1";
	}else{
		cout<<"0";
		
	}
	return 0;
}
