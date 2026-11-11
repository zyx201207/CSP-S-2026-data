//GZ-J00712，申桐薪，个人报名
#include<bits/stdc++.h>
using namespace std;
long c=0,d=0,z=0;
int main(){
	freopen("string.in","r",stdin);
 freopen("string.out","x",stdout);

	int n;//duanshu
	cin>>n;
	string a,s,c;

	cin>>n;
	for(int i=0;i=<n;i++){
		cin>>c>>a;
		d+=c;
		for(int j=0;j<=c;j++){
			s+=a;
		}
	}
	for(int i=0;i<s.length-1;i>0;i--){
		x+=s[i];
		
	}
	for(int i=0;i<s.length;i>0;i++){
		if(x[i]==s[i]) {
			z++
		}
	}
	cou<<z/2<<endl;
	
	
	
	
	
	return 0;
}






  
