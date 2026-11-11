//GZ-J00646		兴义市弘毅中学		马志宸奕	 
#include<bits/stdc++.h>
using namespace std;

string c[2];
string s[2];
string a,b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	for(int i=0;i<2;i++){
		cin>>c[i]>>s[i];
	}
	if(c[0]==c[1]){cout<<1;}
	else{cout<<0<<0<<0<<0;return 0;}
	

	for(int i=0;i<2;i++){
		string q=s[i];
		for(int j=0;j<q.size()-1;j++){
			if(q[j]>='0'&&q[j]<='9'){
				if(i==0)a+=q[j];
				else b+=q[j];
			}
		}
	}
	if(a==b){
		cout<<1;
		string a1=s[0],b1=s[1];
		int a2=a1.size()-1,b2=b1.size()-1;
		if(a1[a2]<='C'&&b1[b2]<='C'||a1[a2]>='D'&&b1[b2]>='D'){
			cout<<1;
			int a3=a1[a2];int b3=b1[b2];
			if(abs(a3-b3)==1){
				cout<<1;
			}
			else{cout<<0;
			}
		}else{cout<<0<<0;
		}
	}
	else cout<<0<<0<<0;
	return 0;
} 
