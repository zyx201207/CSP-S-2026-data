#include<bits/stdc++.h>
using namespace std;
string a,q,hm;
bool huwen(string l,bool f){
	if(l.length()%2==0){
		for(int i=0;i<l.length()/2;i++){
			q+=l[i];
		} 
		for(int i=l.length();i>=l.length()/2;i--){
			hm+=l[i];
		}
	}
	else{
		for(int i=0;i<l.length()/2;i++){
			q+=l[i];
		} 
		for(int i=l.length();i>=l.length()/2+1;i--){
			hm+=l[i];
		}
	}
	if(q==hm){
		return l,1;
	}
	else{
		return l,0;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool m=0;
	char d;
	long long n,h=0,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>d;
		for(int j=1;j<=x;j++){
			a+=d;
		}
	}
	huwen(a,m);
	if(m){
		cout<<0;
	}
	else{
		for(int i=q.length(),j=0;j<q.length();j++,i--){
			if(q[i]!=hm[j]){
				h++;
			} 
		}  
	} 
	cout<<h;
	return 0;
} 
