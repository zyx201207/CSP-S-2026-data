#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string n;
	int a,b,ans=0,d=0,e=1;
	char c;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		while(b){
			n[e]=c;
			e++;
			d++;
			b--;
		}
	}
	if(d%2==0){
		int l=d/2,r=d/2+1;
		while(l){
			if(n[l]==n[r]){
				l--;
				r++;	
			}
			else{
				ans++;
				l--;
				r++;
			}	
		}
	}
	else{
		int l=d/2,r=d/2+2;
		while(l){
			if(n[l]!=n[r]){
				ans++;
			}
			l--;
			r++;
		}
	}
	cout<<ans;
	return 0;
}
