#include <bits/stdc++.h>
using namespace std;
int a[200010],c[200010]={0};
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	char d;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<n;i++){
		if(b[i]==b[i+1]){
			cnt++;
		}
	}
	if(cnt==n-1){
		cout<<"0";
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='a'){
			cnt+=a[i];
			}	
	}	
	c[1]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='b'){
			cnt+=a[i];
			}	
	}	
	c[2]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='c'){
			cnt+=a[i];
			}	
	}	
	c[3]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='d'){
			cnt+=a[i];
			}	
	}	
	c[4]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='e'){
			cnt+=a[i];
			}	
	}	
	c[5]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='f'){
			cnt+=a[i];
			}	
	}	
	c[6]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='g'){
			cnt+=a[i];
			}	
	}	
	c[7]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='h'){
			cnt+=a[i];
			}	
	}	
	c[8]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='i'){
			cnt+=a[i];
			}	
	}	
	c[9]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='j'){
			cnt+=a[i];
			}	
	}	
	c[10]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='k'){
			cnt+=a[i];
			}	
	}	
	c[11]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='l'){
			cnt+=a[i];
			}	
	}	
	c[12]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='m'){
			cnt+=a[i];
			}	
	}	
	c[13]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='n'){
			cnt+=a[i];
			}	
	}	
	c[14]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='o'){
			cnt+=a[i];
			}	
	}	
	c[15]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='p'){
			cnt+=a[i];
			}	
	}	
	c[16]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='q'){
			cnt+=a[i];
			}	
	}	
	c[17]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='r'){
			cnt+=a[i];
			}	
	}	
	c[18]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='s'){
			cnt+=a[i];
			}	
	}	
	c[19]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='t'){
			cnt+=a[i];
			}	
	}	
	c[20]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='u'){
			cnt+=a[i];
			}	
	}	
	c[21]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='v'){
			cnt+=a[i];
			}	
	}	
	c[22]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='w'){
			cnt+=a[i];
			}	
	}	
	c[23]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='x'){
			cnt+=a[i];
			}	
	}	
	c[24]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='y'){
			cnt+=a[i];
			}	
	}	
	c[25]=cnt;
	cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]=='z'){
			cnt+=a[i];
			}	
	}	
	c[26]=cnt;
	cnt=0;	
	int max1=0;	
	for(int i=1;i<=26;i++){
	max1=max(max1,c[i]);
}
	for(int i=1;i<=26;i++){
		if(c[i]==max1){
			for(int j=1;j<=26;j++){
				if(i!=j){
					cnt+=c[j];
				}
			}
			cout<<cnt;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
