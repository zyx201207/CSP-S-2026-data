#include<bits/stdc++.h>
using namespace std;
long long n,d,ans,e=1;
long long c[9000005];
struct p{
	long long shu;
	char zi;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b[i].shu >> b[i].zi;
	}
	for(int i=1;i<=n;i++){
		for(int j=e;j<=b[i].shu+e;j++){
			e++;
			if(b[j].zi=='a'){
				c[j]=1;
			}
			if(b[j].zi=='b'){
				c[j]=2;
			}
			if(b[j].zi=='c'){
				c[j]=3;
			}
			if(b[j].zi=='d'){
				c[j]=4;
			}
			if(b[j].zi=='e'){
				c[j]=5;
			}
			if(b[j].zi=='f'){
				c[j]=6;
			}
			if(b[j].zi=='g'){
				c[j]=7;
			}
			if(b[j].zi=='h'){
				c[j]=8;
			}
			if(b[j].zi=='i'){
				c[j]=9;
			}
			if(b[j].zi=='j'){
				c[j]=10;
			}
			if(b[j].zi=='k'){
				c[j]=11;
			}
			if(b[j].zi=='l'){
				c[j]=12;
			}
			if(b[j].zi=='m'){
				c[j]=13;
			}
			if(b[j].zi=='n'){
				c[j]=14;
			}
			if(b[j].zi=='o'){
				c[j]=15;
			}
			if(b[j].zi=='p'){
				c[j]=16;
			}
			if(b[j].zi=='q'){
				c[j]=17;
			}
			if(b[j].zi=='r'){
				c[j]=18;
			}
			if(b[j].zi=='s'){
				c[j]=19;
			}
			if(b[j].zi=='t'){
				c[j]=20;
			}
			if(b[j].zi=='u'){
				c[j]=21;
			}
			if(b[j].zi=='v'){
				c[j]=22;
			}
			if(b[j].zi=='w'){
				c[j]=23;
			}
			if(b[j].zi=='x'){
				c[j]=24;
			}
			if(b[j].zi=='y'){
				c[j]=25;
			}
			if(b[j].zi=='z'){
				c[j]=26;
			}
		}
	}
	if(n%2==0){
		d=n/2;
	}
	else{
		d=(n/2)+1;	
	}
	for(int i=1;i<=d;i++){
		cout << c[i] << " ";
		if(c[i]!=c[n-i+1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
