#include<bits/stdc++.h>
using namespace std;
bool hui(string x){
	int n=x.size();
	for(int i=0;i<n/2;i++){
		if(x[i]!=x[n-i-1]){return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,m,ans;
	
	int k=0;
	string b;
	cin>>a;
	int c;
	char d;
	char e;
	m=0;
	ans=0;
	for(int i=0;i<a;i++){
		cin>>c>>d;
		if(i==0){e=d;
		}
		
		
		for(int j=0;j<c;j++){
			b+=d;
		}
	}
	int g=b.size();
	
		
	bool tr =hui(b);
	while(!tr){
		if (b[g-m-1]!=e){
		b[g-m-1]=e;
		m++;
		ans++;
		tr=hui(b);		
		}else{m++;}
	}
	
	
	cout<<ans;
	return 0;
}
