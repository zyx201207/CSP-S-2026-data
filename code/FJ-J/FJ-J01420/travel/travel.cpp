#include<bits/stdc++.h>

using namespace std;
int n,m,a[6];
string n1,m1;
bool b=1;
void Main(){
	cin>>n>>n1>>m>>m1;
	if(n==m){
		a[1]=1;
	}else{
		for(int i=1;i<=4;i++){
			cout<<a[i];
			b=0;
		}
	}
	if(b){
		int n2=(n1[0]-'0')*10+(n1[1]-'0');
		int m2=(m1[0]-'0')*10+(m1[1]-'0');
		if(n2==m2){
			a[2]=1;
		}else{
			for(int i=1;i<=4;i++){
				cout<<a[i];
				b=0;
			}
		}
		if(b){
			char n3=n1[2];
			int n3_1;
			char m3=m1[2];
			int m3_1;
			if('A'<=n3&&n3<='C')n3_1=1;
			else n3_1=2;
			if('A'<=m3&&m3<='C')m3_1=1;
			else m3_1=2;
			if(n3_1==m3_1){
				a[3]=1;
			}else{
				for(int i=1;i<=4;i++){
					cout<<a[i];
					b=0;
				}
			}
			if(b){
				if(n3_1==1){
					if(abs(n3-m3)==1)a[4]=1;
				}
				a[4]==1;
				for(int i=1;i<=4;i++){
					cout<<a[i];
				}			
			}	
		}
	
	}
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	Main();
	return 0;
}
