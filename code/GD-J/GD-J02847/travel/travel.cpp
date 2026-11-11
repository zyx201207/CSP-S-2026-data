include <bits/stdc++.h>
using namespace std;
int s1[1000005]
int s2[1000005]
int c1,c2;
int main(){
	froepen("travel.in",'r',inside);
	froepen("travel.out",'w',outside);

	cin>>c1>>s1>>c2>>s2;
	if (c1=c2&&s1[0]=s2[0]&&s1[1]=s2[1]&&abs(s2[2]-s1[2])=1){
		cout<<"1111"<<endl;
	}
	else if(c1=c2&&s1[0]=s2[0]&&s1[1]=s2[1]&&abs(s2[2]-s1[2])!=1){
		cout<<"1110"<<endl;
	}
	else if(c1=c2&&s1[0]=s2[0]&&s1[1]=s2[1]&&(abs(s2[2]-s1[2]>=1)&&s1[2]<s2[2])){
		cout<<1100"<<endl;
	}
	else if(c1=c2&&s1[0]=s2[0]&&s1[1]!=s2[1]&&abs(s2[2]-s1[2]=1)){
		cout<<1000"<<endl;
	}
	else if(c1!=c2&&s1[0]=s2[0]&&s1[1]=s2[1]&&s1[2]=s2[2]){
		cout<<0000"<<endl;
	}
	return 0;
	
}
