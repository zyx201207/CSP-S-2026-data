#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int l;
int k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>a>>s>>d>>f;
	for(int i=0;i<2;i++){
		if(a[i]!=d[i]){
			cout<<0;
			l++;
			break;
		}
	}
	if(l==0){
		k++;
		cout<<1;
	}
	l=l-l;
	if(k>0){
		k=k-k;
		for(int i=0;i<2;i++){
			if(s[i]!=f[i]){
				cout<<0;
				l++;
				break;
			}
		}
		if(l==0){
			k++;
			cout<<1;
		}
		l=l-l;
		if(k>0){
			if(s[2]=='A'){
				if(f[2]=='B'||f[2]=='C'){
					cout<<1;
					l++;
				}
			}else if(s[2]=='D'&&f[2]=='F'){
				cout<<1;
				l++;
			}else if(s[2]=='B'){
				if(f[2]=='A'||f[2]=='C'){
					cout<<1;
					l++;
				}
			}else if(s[2]=='F'&&f[2]=='D'){
				cout<<1;
				l++;
			}else if(s[2]=='C'){
				if(f[2]=='A'||f[2]=='B'){
					cout<<1;
					l++;
				}
			}
			if(l==0){
				cout<<0;
			}
			l=l-l;
		
			if(s[2]=='A'&&f[2]=='B'){
				cout<<1;
				l++;
			}else if(s[2]=='D'&&f[2]=='F'){
				cout<<1;
				l++;
			}else if(s[2]=='B'){
				if(f[2]=='A'||f[2]=='C'){
					cout<<1;
					l++;
				}
			}else if(s[2]=='F'&&f[2]=='D'){
				cout<<1;
				l++;
			}else if(s[2]=='C'&&f[2]=='B'){
				cout<<1;
				l++;
			}
			if(l==0){
				cout<<0;
			}
			l=l-l;
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
	}
	return 0;
}
