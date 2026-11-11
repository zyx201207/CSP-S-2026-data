#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2,a[4]={0};
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]=1;
	}

	if(s1[2]<68&&s2[2]<68||s1[2]>67&&s2[2]>67){
		a[2]=1;
		if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
			a[3]=1;
		}
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0; 
}
