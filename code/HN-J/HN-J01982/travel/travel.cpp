#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
bool a[6][18];
int b[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
		int temp=(s1[0]-'0')*10+s1[1]-'0';
		if(s1[2]='A'){
			a[temp][6]=1;
		}else if(s1[2]='B'){
			a[temp][5]=1;
		}else if(s1[2]='C'){
			a[temp][4]=1;
		}else if(s1[2]='D'){
			a[temp][2]=1;
		}else if(s1[2]='F'){
			a[temp][1]=1;
		}
		int temp1=(s2[0]-'0')*10+s2[1]-'0';
		if(s2[2]='A'){
			a[temp1][6]=1;
		}else if(s2[2]='B'){
			a[temp1][5]=1;
		}else if(s2[2]='C'){
			a[temp1][4]=1;
		}else if(s2[2]='D'){
			a[temp1][2]=1;
		}else if(s2[2]='F'){
			a[temp1][1]=1;
		}
	}
	int wer=1;
	for(int i=1;i<=19;i++){
		for(int j=1;j<=19;j++){
			if(a[i][j]=1){
				b[wer]=i;
				wer++;
				b[wer]=j;
				wer++;
				
			}
		}
	if(b[2]==b[4]){
		cout<<1;

	}else{
		cout<<0;
	}
	if(b[2]==b[4]){
		if(b[1]>=4&&b[3]>=4||b[1]<=2&&b[3]<=2){
		    cout<<1;
		}else{
			cout<<0;
		}
	}

	if(b[1]-b[3]==1||b[3]-b[1]==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
   }
}
