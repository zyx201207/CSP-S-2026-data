#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	char b;
}s[200005],g;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	g.a=0;
	int n;
	long long c=0;
	bool f=1;
	string s1="";
	cin >> n;
	if(n>5000){
		f=0;
	}
	for(int i=0;i<n;i++){
		cin >> s[i].a >> s[i].b;
		if(s[i].a>50000){
			f=0;
		}else{
			for(int j=0;j<s[i].a;j++){
				s1+=s[i].b;
			}
		}
	}
	if(!f){
	long long l=0,r=n-1;
	while(l<r){
		if(s[l].a!=s[r].a){
			g.a=abs(s[l].a-s[r].a);
			for(int i=r-1;i>l&&g.a>0;i--){
				if(s[l].b==s[i].b){
					if(g.a>=s[i].a){
						g.a-=s[i].a;
						s[i].a=0;
					}else{
						s[i].a-=g.a;
						g.a=0;
					}	
				}else{
					if(g.a<s[i].a){
						c+=g.a; 
						s[i].a-=g.a;
						g.a=0;
					}else{
						g.a-=s[i].a;
						c+=s[i].a;
						s[i].a=0;
					}
				}
			}
		}else if(s[l].b!=s[r].b){
			c+=s[l].a;
		}
		l++;
		r--;
	}
}else{
	int l=0,r=s1.size()-1;
	while(l<r){
		if(s1[l]!=s1[r]){
			c++;
		}
		l++;
		r--;
	}
} 
	if(g.a!=0){
		c+=g.a;
		}
	cout << c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

