#include<bits/stdc++.h>
using namespace std;
long long a=1,b,c,n;
char ine,s[1000000005];
void print(){
	cout<<endl;
	for(int i=0;i<b;i++){
		cout<<s[i];
	}
}
struct ab{
	long long o,k,ds;
	char x;
}l[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ine;
		l[i].o=b;
		b+=a;
		l[i].k=b;
		l[i].x=ine;
		l[i].ds=a;
	}
	int dao=n;
	for(int i=1;i<=n/2;i++){
		long long oo=l[i].o,kk=l[i].k,oi=l[dao].o,ki=l[dao].k;
		if(b-1-kk<=oi){
			while(b-1-kk>oi){
				if(l[i].x!=l[dao].x) c+=b-1-oo-oi;
			    dao--;
			    oi=l[dao].o;
			    ki=l[dao].k;
			}
			if(l[i].x!=l[dao].x) c+=kk-oo;
		}
		else{
			if(l[i].x!=l[dao].x) c+=kk-oo;
		}
	}
	cout<<c;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
