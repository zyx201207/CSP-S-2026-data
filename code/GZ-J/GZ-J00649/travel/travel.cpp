//GZ-J00649КывужабЇ ЭѕГЏюч 
#include<bits/stdc++.h> 
using namespace std;
string s1,s2;
char n1,n2;
long long c1,c2,a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	n1=s1[2]; n2=s2[2];
	long long x1=n1,x2=n2;
	if(x2>x1){
		long long b=x1;
		x1=x2;
		x2=b;
	}
	long long sum=x1-x2;
	if(c1==c2){
		a[1]=1;
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
		a[2]=1;
		if(n1>'C'&&n2>'C'){
			a[3]=1;
			if(sum==2){
				a[4]=1;
			}
		}else if(n1<'D'&&n2<'D'){
			a[3]=1;
			if(sum==1){
				a[4]=1;
			}
		}
		}else if(s1[0]==s2[0]&&(s1[1]==s2[1]-'1'||s1[1]-'1'==s2[1])){
		a[1]=1;
		}
	}
	

	for(int i=1;i<=4;i++){
		if(a[1]==0){
			while(a[i]==0){
				if(i==4){
					break;
				}
				i++;
				}
			}
		cout<<a[i];
	}
	
	
	
	return 0;
}
