#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int a,b,c,d;
int main (){
	freopen("travel.stdin","r",stdin);
	freopen("travel.stdout","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=1;
	}else{
		a=0;
	}
	if(a==0){
		b=0;
		c=0;
		d=0;
	}else{
		for(int i = 1;i<=1;i++){
		if(s1[i]==s2[i]||s1[i+1]==s2[i+1]){
			b=1;
		} else{
			b=0;
		}
		if(b=0){
			c=0;
			d=0;
		}
	}
	}
	
	if(b=1){
		for(int j = 1;j<=1;j++){
		if(s1[j+2]=='A'||s2[j+2]=='B'&&s1[j+2]=='B'||s2[j+2]=='A'){
			c=1;
			d=1;
		}else{
			if(s1[j+2]=='B'||s2[j+2]=='C'&&s1[j+2]=='C'||s2[j+2]=='B'){
				c=1;
				d=1;
			} else{
				if(s1[j+2]=='C'||s2[j+2]=='D'&&s1[j+2]=='D'||s2[j+2]=='C'){
					c=0;
					d=0;
				}else{
					if(s1[j+2]=='A'||s2[j+2]=='D'&&s1[j+2]=='D'||s2[j+2]=='A'){
						c=0;
						d=0;
					}else{
						if(s1[j+2]=='A'||s2[j+2]=='F'&&s1[j+2]=='F'||s2[j+2]=='A'){
							c=0;
							d=0;
						}else{
							if(s1[j+2]=='B'||s2[j+2]=='D'&&s1[j+2]=='D'||s2[j+2]=='B'){
								c=0;
								d=0;
							}else{
								if(s1[j+2]=='B'||s2[j+2]=='F'&&s1[j+2]=='F'||s2[j+2]=='B'){
									c=0;
									d=0;
								}else{
									if(s1[j+2]=='C'||s2[j+2]=='F'&&s1[j+2]=='F'||s2[j+2]=='C'){
										c=0;d=0;
									}else{
										if(s1[j+2]=='D'||s2[j+2]=='F'&&s1[j+2]=='F'||s2[j+2]=='D'){
											c=1;
											d=1;
										}else{
											if(s1[j+2]=='A'||s2[j+2]=='C'&&s1[j+2]=='C'||s2[j+2]=='A'){
												c=1;
												d=0;
											}
										}
									}
								}
							}
						} 
					}
				}
			}
		}
		
	}

	}
	
	cout<<a<<b<<c<<d;
	return 0;
}

