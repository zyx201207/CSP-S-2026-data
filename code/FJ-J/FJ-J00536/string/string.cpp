#include<bits/stdc++.h>
using namespace std;
const int MAXN=124715400;
unsigned int a[MAXN],b[MAXN];
int n,z,ans;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n==1){
		char c;
		cin >> a[1] >> c;
		cout << 0; 
		return 0;
	}
	for(int i=1;i<=n;i++){
		char c;
		cin >> a[i] >> c;
		if(c=='a'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=1;
			}
		}else if(c=='b'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=2;
			}
		}else if(c=='c'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=3;
			}
		}else if(c=='d'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=4;
			}
		}else if(c=='e'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=5;
			}
		}else if(c=='f'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=6;
			}
		}else if(c=='g'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=7;
			}
		}else if(c=='h'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=8;
			}
		}else if(c=='i'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=9;
			}
		}else if(c=='j'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=10;
			}
		}else if(c=='k'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=11;
			}
		}else if(c=='l'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=12;
			}
		}else if(c=='m'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=13;
			}
		}else if(c=='n'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=14;
			}
		}else if(c=='o'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=15;
			}
		}else if(c=='p'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=16;
			}
		}else if(c=='q'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=17;
			}
		}else if(c=='r'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=18;
			}
		}else if(c=='s'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=19;
			}
		}else if(c=='t'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=20;
			}
		}else if(c=='u'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=21;
			}
		}else if(c=='v'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=22;
			}
		}else if(c=='w'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=23;
			}
		}else if(c=='x'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=24;
			}
		}else if(c=='y'){
			for(int j=z;j<=z+a[i];j++){
				b[j]=25;
			}
		}else{
			for(int j=z;j<=z+a[i];j++){
				b[j]=26;
			}
		}
		z+=a[i];
	}
	for(int i=1;i<=z/2+z%2;i++){
		if(b[i]!=b[z+1-i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
