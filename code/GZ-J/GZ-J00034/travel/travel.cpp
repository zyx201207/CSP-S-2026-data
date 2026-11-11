//GZ-J00034，邵葛锦华，贵阳市观山湖区外国语实验中学 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>a>>b>>c>>d;
	string b1,d1;
	int len1=0,len2=0;
	char ans[4];
	for(int i=1;i<2;i++){
		len1=len1*10+(b[i]-'0');
		len2=len2*10+(d[i]-'0');
		b1+=b[i];
		d1+=d[i];
	}
	if(a==c){
		ans[0]='1';
	}else{
		ans[0]='0';
	}
	if(a==c&&b1==d1){
		ans[1]='1';
		if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C'){
			ans[2]='1';
			if(abs(b[2]-d[2])==1){
				ans[3]='1';
			}else{
				ans[3]='0';
			}
		}else{
			ans[2]='0',ans[3]='0';
		}
	}else{
		ans[2]='0',ans[3]='0',ans[1]='0';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

